#include "mvf.h"

// Function to move files from Windows to WSL
int move_to_wsl(const char *win_path, const char *wsl_dest) {
    char wsl_source[MAX_PATH];
    char full_wsl_dest[MAX_PATH];
    char command[MAX_COMMAND];
    char username[256];
    
    // Get Windows username
    if (get_windows_username(username, sizeof(username)) != 0) {
        fprintf(stderr, "Error: Could not fetch Windows username.\n");
        return 1;
    }
    
    // Convert Windows path to WSL mount path
    convert_windows_path_to_wsl(win_path, wsl_source, sizeof(wsl_source));
    
    // Check if source exists
    if (!file_exists(wsl_source)) {
        fprintf(stderr, "Error: Path %s does not exist in Windows.\n", wsl_source);
        return 1;
    }
    
    // Create full destination path
    if (wsl_dest[0] == '/') {
        snprintf(full_wsl_dest, sizeof(full_wsl_dest), "%s", wsl_dest);
    } else {
        snprintf(full_wsl_dest, sizeof(full_wsl_dest), "%s/%s", getenv("HOME"), wsl_dest);
    }
    
    // Create destination directory
    if (create_directory_recursive(full_wsl_dest) != 0) {
        fprintf(stderr, "Error: Could not create destination directory %s\n", full_wsl_dest);
        return 1;
    }
    
    // Execute rsync command in quiet mode
    snprintf(command, sizeof(command), "rsync -aq \"%s\" \"%s\"", wsl_source, full_wsl_dest);
    
    if (execute_command(command) == 0) {
        printf("Successfully moved '%s' to '%s'\n", win_path, wsl_dest);
        return 0;
    } else {
        fprintf(stderr, "Error: Move operation failed.\n");
        return 1;
    }
}

// Function to move files from WSL to Windows
int move_to_win(const char *wsl_source, const char *win_dest) {
    char full_wsl_source[MAX_PATH];
    char win_dest_path[MAX_PATH];
    char command[MAX_COMMAND];
    char username[256];
    
    // Get Windows username
    if (get_windows_username(username, sizeof(username)) != 0) {
        fprintf(stderr, "Error: Could not fetch Windows username.\n");
        return 1;
    }
    
    // Create full WSL source path
    if (wsl_source[0] == '/') {
        snprintf(full_wsl_source, sizeof(full_wsl_source), "%s", wsl_source);
    } else {
        snprintf(full_wsl_source, sizeof(full_wsl_source), "%s/%s", getenv("HOME"), wsl_source);
    }
    
    // Check if source exists
    if (!file_exists(full_wsl_source)) {
        fprintf(stderr, "Error: Path %s does not exist in WSL.\n", full_wsl_source);
        return 1;
    }
    
    // Create Windows destination path
    snprintf(win_dest_path, sizeof(win_dest_path), "/mnt/c/Users/%s/%s", username, win_dest);
    
    // Create destination directory
    if (create_directory_recursive(win_dest_path) != 0) {
        fprintf(stderr, "Error: Could not create destination directory %s\n", win_dest_path);
        return 1;
    }
    
    // Execute rsync command in quiet mode
    snprintf(command, sizeof(command), "rsync -aq \"%s\" \"%s\"", full_wsl_source, win_dest_path);
    
    if (execute_command(command) == 0) {
        printf("Successfully moved '%s' to '%s'\n", wsl_source, win_dest);
        return 0;
    } else {
        fprintf(stderr, "Error: Move operation failed.\n");
        return 1;
    }
} 