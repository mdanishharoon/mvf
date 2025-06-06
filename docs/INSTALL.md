# MVF Installation Guide

## Quick Install

```bash
# Clone or download the project
git clone <your-repo-url>
cd mvf

# Build and install system-wide
make install
```

## Installation Commands

| Command | Description |
|---------|-------------|
| `make` | Compile the program |
| `make install` | Install to system PATH (requires sudo) |
| `make check` | Verify installation |
| `make uninstall` | Remove from system |
| `make clean` | Clean build files |

## Usage After Installation

Once installed, you can use `mvf` from anywhere:

```bash
# From any directory
mvf to-wsl "Downloads/file.txt" "Documents/"
mvf to-win "Documents/project" "Desktop/Backup/"
```

## Installation Details

- **Install Location**: `/usr/local/bin/mvf`
- **Requirements**: 
  - GCC compiler
  - sudo privileges for installation
  - WSL environment (for Windows-WSL transfers)
  - rsync
  - PowerShell (for Windows username detection)

## Verification

Check if mvf is properly installed:

```bash
make check
# or
which mvf
# or
mvf --help
```

## Troubleshooting

### Command not found after installation
- Make sure `/usr/local/bin` is in your PATH
- Check with: `echo $PATH | grep /usr/local/bin`
- If missing, add to your shell profile:
  ```bash
  echo 'export PATH="/usr/local/bin:$PATH"' >> ~/.bashrc
  source ~/.bashrc
  ```

### Permission denied during install
- Make sure you have sudo privileges
- The install command requires root access to write to `/usr/local/bin/`

### Installation verification fails
- Run `make check` to see detailed status
- Ensure the installation completed without errors
- Try reinstalling: `make uninstall && make install`

## Alternative Installation Locations

To install to a different location, modify the `INSTALL_DIR` in Makefile:

```makefile
INSTALL_DIR = /usr/bin          # System-wide (requires sudo)
INSTALL_DIR = $(HOME)/bin       # User-specific (no sudo needed)
INSTALL_DIR = $(HOME)/.local/bin # User-specific (common location)
```

Then run `make install` as usual. 