
import 'copy_file_to_clipboard_platform_interface.dart';

class CopyFileToClipboard {
  Future<String?> getPlatformVersion() {
    return CopyFileToClipboardPlatform.instance.getPlatformVersion();
  }

  Future<void> copyFilesToClipboard(List<String> paths) {
    return CopyFileToClipboardPlatform.instance.copyFilesToClipboard(paths);
  }
}
