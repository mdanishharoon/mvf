# mvf: A Script for Moving Files Between Windows and WSL

`mvf` (Move File) is a command-line utility for the Windows Subsystem for Linux (WSL) that simplifies moving files and directories between the Windows and WSL filesystems. It automatically handles the complex path translations, so you don't have to manually type out paths like `/mnt/c/Users/YourUser/...`.

## Overview

Working in a mixed Windows and WSL environment often requires transferring files back and forth and I wanted a clean and simple way to transfer files back and forth between windows and wsl home directories. This script streamlines that process by providing a simple, intuitive syntax to streamline file transfers. I wrote this to specifically move files between my upper level directories on windows and wsl and so havent tested it out much on absolute paths myself. feel free to make any improvements and make a PR.

## Installation

1. **Save the Script**: Save the provided script code into a file named `mvf`.
2. **Make it Executable**: Open your WSL terminal and run the following command to grant execute permissions to the script.

    ```bash
    chmod +x mvf
    ```

3. **Move to your PATH (Recommended)**: To use the `mvf` command from any directory, move it to a location included in your system's PATH. A common choice is `/usr/local/bin`.

    ```bash
    sudo mv mvf /usr/local/bin/
    ```

Now you can simply type `mvf` in your terminal, no matter your current location.

## Usage

The script's syntax is based on specifying the direction of the transfer (`to-wsl` or `to-win`), followed by the source and destination paths.

### Syntax

- **Move from Windows to WSL**:

    ```bash
    mvf to-wsl <windows_path> <wsl_destination>
    ```

- **Move from WSL to Windows**:

    ```bash
    mvf to-win <wsl_path> <windows_destination>
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
