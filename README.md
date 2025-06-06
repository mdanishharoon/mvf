# MVF - Move Files (Windows ↔ WSL)

 `mvf` (Move File) is a fast, shell-agnostic command-line utility for the Windows Subsystem for Linux (WSL) that simplifies moving files and directories between the Windows and WSL filesystems. It automatically handles the complex path translations, so you don't have to manually type out paths like `/mnt/c/Users/YourUser/...`.


## Features

- **Shell-agnostic**: Works with any shell (bash, zsh, fish, etc.)
- **Auto-directory creation**: Creates nested destination directories automatically
- **Bidirectional**: Transfer files both ways (Windows ↔ WSL)

## Quick Start

```bash
# Install
git clone https://github.com/mdanishharoon/mvf
cd mvf
make install

# Use from anywhere
mvf to-wsl "Downloads/file.txt" "Documents/"
mvf to-win "Documents/project" "Desktop/Backup/"
```





### Examples

1. **Move a file from Windows Downloads to WSL**

    To move a file named `report.docx` from your Windows Downloads folder to your current directory in WSL:

    ```bash
    # Usage: mvf to-wsl <windows_relative_path> <wsl_destination>
    mvf to-wsl Downloads/report.docx .
    ```

2. **Move a file from WSL to Windows Documents**

    To move `archive.zip` from your WSL home directory (`~`) to your Windows Documents folder:

    ```bash
    # Usage: mvf to-win <wsl_path> <windows_relative_path>
    mvf to-win archive.zip Documents/
    ```

3. **Move a folder from WSL to the Windows Desktop**

    To move a directory named `project-files` from WSL's home folder to a new folder called `backup` on your Windows Desktop:

    ```bash
    # This will create C:\Users\YourUser\Desktop\backup\project-files
    mvf to-win project-files Desktop/backup/
    ```

## Documentation

- **[Installation Guide](docs/INSTALL.md)** - Detailed installation instructions
- **[Technical Documentation](docs/README-C.md)** - Code structure and implementation details


## Contributing

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Test thoroughly
5. Submit a pull request

## 📄 License

See [LICENSE](LICENSE) file for details. 