#ifndef FLUTTER_PLUGIN_COPY_FILE_TO_CLIPBOARD_PLUGIN_H_
#define FLUTTER_PLUGIN_COPY_FILE_TO_CLIPBOARD_PLUGIN_H_

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>

#include <memory>

namespace copy_file_to_clipboard {

class CopyFileToClipboardPlugin : public flutter::Plugin {
 public:
  static void RegisterWithRegistrar(flutter::PluginRegistrarWindows *registrar);

  CopyFileToClipboardPlugin();

  virtual ~CopyFileToClipboardPlugin();

  // Disallow copy and assign.
  CopyFileToClipboardPlugin(const CopyFileToClipboardPlugin&) = delete;
  CopyFileToClipboardPlugin& operator=(const CopyFileToClipboardPlugin&) = delete;

  // Called when a method is called on this plugin's channel from Dart.
  void HandleMethodCall(
      const flutter::MethodCall<flutter::EncodableValue> &method_call,
      std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result);
};

}  // namespace copy_file_to_clipboard

#endif  // FLUTTER_PLUGIN_COPY_FILE_TO_CLIPBOARD_PLUGIN_H_
