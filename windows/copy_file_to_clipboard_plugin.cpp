#include "copy_file_to_clipboard_plugin.h"

// This must be included before many other Windows headers.
#include <windows.h>

// For getPlatformVersion; remove unless needed for your plugin implementation.
#include <VersionHelpers.h>

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>
#include <flutter/standard_method_codec.h>

#include <memory>
#include <sstream>
#include <shlobj.h>
#include <vector>

namespace copy_file_to_clipboard {

// static
void CopyFileToClipboardPlugin::RegisterWithRegistrar(
    flutter::PluginRegistrarWindows *registrar) {
  auto channel =
      std::make_unique<flutter::MethodChannel<flutter::EncodableValue>>(
          registrar->messenger(), "copy_file_to_clipboard",
          &flutter::StandardMethodCodec::GetInstance());

  auto plugin = std::make_unique<CopyFileToClipboardPlugin>();

  channel->SetMethodCallHandler(
      [plugin_pointer = plugin.get()](const auto &call, auto result) {
        plugin_pointer->HandleMethodCall(call, std::move(result));
      });

  registrar->AddPlugin(std::move(plugin));
}

CopyFileToClipboardPlugin::CopyFileToClipboardPlugin() {}

CopyFileToClipboardPlugin::~CopyFileToClipboardPlugin() {}

void CopyFileToClipboardPlugin::HandleMethodCall(
    const flutter::MethodCall<flutter::EncodableValue> &method_call,
    std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result) {
  if (method_call.method_name().compare("getPlatformVersion") == 0) {
    std::ostringstream version_stream;
    version_stream << "Windows ";
    if (IsWindows10OrGreater()) {
      version_stream << "10+";
    } else if (IsWindows8OrGreater()) {
      version_stream << "8";
    } else if (IsWindows7OrGreater()) {
      version_stream << "7";
    }
    result->Success(flutter::EncodableValue(version_stream.str()));
  } else if (method_call.method_name().compare("copyFilesToClipboard") == 0) {
    const auto* arguments = std::get_if<flutter::EncodableList>(method_call.arguments());
    if (!arguments) {
      result->Error("Invalid arguments", "Expected a list of file paths.");
      return;
    }

    std::vector<std::wstring> file_paths;
    for (const auto& arg : *arguments) {
      if (const auto* path = std::get_if<std::string>(&arg)) {
        file_paths.push_back(std::wstring(path->begin(), path->end()));
      }
    }

    if (OpenClipboard(nullptr)) {
      EmptyClipboard();

      size_t total_size = 0;
      for (const auto& path : file_paths) {
        total_size += (path.size() + 1) * sizeof(wchar_t);
      }
      total_size += sizeof(DROPFILES);

      HGLOBAL hGlobal = GlobalAlloc(GHND, total_size);
      if (hGlobal) {
        DROPFILES* pDropFiles = (DROPFILES*)GlobalLock(hGlobal);
        pDropFiles->pFiles = sizeof(DROPFILES);
        pDropFiles->fWide = TRUE;

        wchar_t* pDst = (wchar_t*)((BYTE*)pDropFiles + sizeof(DROPFILES));
        for (const auto& path : file_paths) {
          wcscpy_s(pDst, path.size() + 1, path.c_str());
          pDst += path.size() + 1;
        }
        GlobalUnlock(hGlobal);
        SetClipboardData(CF_HDROP, hGlobal);
      }
      CloseClipboard();
      result->Success(flutter::EncodableValue(true));
    } else {
      result->Error("Clipboard error", "Failed to open clipboard.");
    }
  } else {
    result->NotImplemented();
  }
}

}  // namespace copy_file_to_clipboard
