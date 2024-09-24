#include "include/copy_file_to_clipboard/copy_file_to_clipboard_plugin_c_api.h"

#include <flutter/plugin_registrar_windows.h>

#include "copy_file_to_clipboard_plugin.h"

void CopyFileToClipboardPluginCApiRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar) {
  copy_file_to_clipboard::CopyFileToClipboardPlugin::RegisterWithRegistrar(
      flutter::PluginRegistrarManager::GetInstance()
          ->GetRegistrar<flutter::PluginRegistrarWindows>(registrar));
}
