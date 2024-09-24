import 'package:flutter_test/flutter_test.dart';
import 'package:copy_file_to_clipboard/copy_file_to_clipboard.dart';
import 'package:copy_file_to_clipboard/copy_file_to_clipboard_platform_interface.dart';
import 'package:copy_file_to_clipboard/copy_file_to_clipboard_method_channel.dart';
import 'package:plugin_platform_interface/plugin_platform_interface.dart';

class MockCopyFileToClipboardPlatform
    with MockPlatformInterfaceMixin
    implements CopyFileToClipboardPlatform {

  @override
  Future<String?> getPlatformVersion() => Future.value('42');

  @override
  Future<void> copyFilesToClipboard(List<String> paths) {
    throw UnimplementedError();
  }
}

void main() {
  final CopyFileToClipboardPlatform initialPlatform = CopyFileToClipboardPlatform.instance;

  test('$MethodChannelCopyFileToClipboard is the default instance', () {
    expect(initialPlatform, isInstanceOf<MethodChannelCopyFileToClipboard>());
  });

  test('getPlatformVersion', () async {
    CopyFileToClipboard copyFileToClipboardPlugin = CopyFileToClipboard();
    MockCopyFileToClipboardPlatform fakePlatform = MockCopyFileToClipboardPlatform();
    CopyFileToClipboardPlatform.instance = fakePlatform;

    expect(await copyFileToClipboardPlugin.getPlatformVersion(), '42');
  });

  test('copyFilesToClipboard', () async {
    CopyFileToClipboard copyFileToClipboardPlugin = CopyFileToClipboard();
    MockCopyFileToClipboardPlatform fakePlatform = MockCopyFileToClipboardPlatform();
    CopyFileToClipboardPlatform.instance = fakePlatform;

    expect(() => copyFileToClipboardPlugin.copyFilesToClipboard(['C:/Windows/win.ini']), throwsUnimplementedError);
  });
}
