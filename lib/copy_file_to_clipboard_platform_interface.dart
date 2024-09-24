import 'package:plugin_platform_interface/plugin_platform_interface.dart';

import 'copy_file_to_clipboard_method_channel.dart';

abstract class CopyFileToClipboardPlatform extends PlatformInterface {
  /// Constructs a CopyFileToClipboardPlatform.
  CopyFileToClipboardPlatform() : super(token: _token);

  static final Object _token = Object();

  static CopyFileToClipboardPlatform _instance = MethodChannelCopyFileToClipboard();

  /// The default instance of [CopyFileToClipboardPlatform] to use.
  ///
  /// Defaults to [MethodChannelCopyFileToClipboard].
  static CopyFileToClipboardPlatform get instance => _instance;

  /// Platform-specific implementations should set this with their own
  /// platform-specific class that extends [CopyFileToClipboardPlatform] when
  /// they register themselves.
  static set instance(CopyFileToClipboardPlatform instance) {
    PlatformInterface.verifyToken(instance, _token);
    _instance = instance;
  }

  Future<String?> getPlatformVersion() {
    throw UnimplementedError('platformVersion() has not been implemented.');
  }

  Future<void> copyFilesToClipboard(List<String> paths) {
    throw UnimplementedError('copyFilesToClipboard() has not been implemented.');
  }
}
