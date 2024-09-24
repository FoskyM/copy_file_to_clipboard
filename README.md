# copy_file_to_clipboard

A Flutter plugin for copying files to the clipboard on Windows platform.

## Usage

To use this plugin, add `copy_file_to_clipboard` as a [dependency in your pubspec.yaml file](https://flutter.dev/docs/development/packages-and-plugins/using-packages).

### Example

```dart
import 'package:flutter/material.dart';
import 'package:copy_file_to_clipboard/copy_file_to_clipboard.dart';

void main() {
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(title: Text('Copy File To Clipboard Example')),
        body: Center(child: CopyFileButton()),
      ),
    );
  }
}

class CopyFileButton extends StatelessWidget {
  final copyFileToClipboard = CopyFileToClipboard();

  @override
  Widget build(BuildContext context) {
    return TextButton(
      onPressed: () async {
        await _copyFileToClipboardPlugin.copyFilesToClipboard(['path/to/your/file1', 'path/to/your/file2']);
        ScaffoldMessenger.of(context).showSnackBar(
          SnackBar(content: Text('Files copied to clipboard')),
        );
      },
      child: Text('Copy Files'),
    );
  }
}
```

## Supported Platforms

- Windows

Only supports Windows platform now.

## License

This plugin is available under the [MIT License](https://opensource.org/licenses/MIT).