import 'package:flutter/services.dart';
import 'package:flutter_test/flutter_test.dart';
import 'package:copy_file_to_clipboard/copy_file_to_clipboard_method_channel.dart';

void main() {
  TestWidgetsFlutterBinding.ensureInitialized();

  MethodChannelCopyFileToClipboard platform = MethodChannelCopyFileToClipboard();
  const MethodChannel channel = MethodChannel('copy_file_to_clipboard');

  setUp(() {
    TestDefaultBinaryMessengerBinding.instance.defaultBinaryMessenger.setMockMethodCallHandler(
      channel,
      (MethodCall methodCall) async {
        return '42';
      },
    );
  });

  tearDown(() {
    TestDefaultBinaryMessengerBinding.instance.defaultBinaryMessenger.setMockMethodCallHandler(channel, null);
  });

  test('getPlatformVersion', () async {
    expect(await platform.getPlatformVersion(), '42');
  });
}
