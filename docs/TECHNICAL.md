# MVF

A shell-agnostic, modular C implementation of the file transfer utility for moving files between Windows and WSL.

## Features

- **Shell-agnostic**: Works with any shell (bash, zsh, fish, etc.)
- **Modular design**: Well-organized code structure for maintainability
- **Automatic directory creation**: Creates nested destination directories if they don't exist
- **Cross-platform file transfers**: Move files between Windows and WSL environments
- **Path handling**: Supports both absolute and relative paths

## Code Structure

The project is organized into modular files for better maintainability:

```
mvf/
├── src/                    # Source code
│   ├── main.c             # Program entry point and argument parsing
│   ├── utils.c            # Utility functions (directory creation, file operations)
│   ├── windows.c          # Windows-specific functions (username, path conversion)
│   └── transfer.c         # Core file transfer logic for both directions
├── include/                # Header files
│   └── mvf.h             # Main header with all declarations and includes
├── docs/                   # Documentation
│   ├── INSTALL.md         # Installation guide
│   └── README-C.md        # This technical documentation
├── scripts/                # Build and utility scripts
│   └── build.sh          # Convenient build script
└── Makefile               # Build configuration
```

### File Breakdown:

- **`include/mvf.h`**: Common header with all function declarations and includes
- **`src/main.c`**: Entry point, argument parsing, and usage display
- **`src/utils.c`**: General utilities like recursive directory creation and file existence checking
- **`src/windows.c`**: Windows-specific operations like username detection and path conversion
- **`src/transfer.c`**: Main transfer logic for both `to-wsl` and `to-win` operations

## Compilation

```bash
# Direct make commands
make                    # Compile the program (builds all modules)
make install           # Install to system (optional)
make clean             # Clean build files
make uninstall         # Uninstall from system

# Using the build script
./scripts/build.sh build      # Build the project
./scripts/build.sh install    # Build and install
./scripts/build.sh clean      # Clean artifacts
./scripts/build.sh check      # Verify installation
```

## Usage

```bash
# Move from Windows to WSL
./mvf to-wsl <windows_path> <wsl_destination>

# Move from WSL to Windows  
./mvf to-win <wsl_path> <windows_destination>
```

## Examples

```bash
# Move a folder from Windows Downloads to WSL
./mvf to-wsl "Downloads/MyFolder" "Documents/Projects"

# Move with nested directory creation
./mvf to-wsl "Downloads/include" "Projects/NewFolder"

# Move from WSL to Windows with directory creation
./mvf to-win "Documents/myfile.txt" "Downloads/NewFolder"

# Using absolute Windows paths
./mvf to-wsl "C:/Users/username/Desktop/file.txt" "Desktop/"
```

## Requirements

- GCC compiler
- WSL environment (for Windows-WSL transfers)
- rsync (for file synchronization)
- PowerShell (for Windows username detection)



- **Utils**: Recursive directory creation using `mkdir()` system calls, file existence checking
- **Windows**: Username detection via PowerShell, path conversion between Windows and WSL formats
- **Transfer**: Main file transfer logic using rsync, error handling for both directions
- **Main**: Command line argument parsing and program flow control

