import 'package:flutter/foundation.dart';
import 'package:flutter/services.dart';

import 'copy_file_to_clipboard_platform_interface.dart';

/// An implementation of [CopyFileToClipboardPlatform] that uses method channels.
class MethodChannelCopyFileToClipboard extends CopyFileToClipboardPlatform {
  /// The method channel used to interact with the native platform.
  @visibleForTesting
  final methodChannel = const MethodChannel('copy_file_to_clipboard');

  @override
  Future<String?> getPlatformVersion() async {
    final version = await methodChannel.invokeMethod<String>('getPlatformVersion');
    return version;
  }

  @override
  Future<void> copyFilesToClipboard(List<String> paths) async {
    await methodChannel.invokeMethod<void>('copyFilesToClipboard', paths);
  }
}
