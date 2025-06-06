#include "mvf.h"

// Function to get Windows username
int get_windows_username(char *username, size_t size) {
    FILE *fp;
    char command[] = "powershell.exe -Command \"[System.Security.Principal.WindowsIdentity]::GetCurrent().Name.Split('\\')[1]\" 2>/dev/null";
    
    fp = popen(command, "r");
    if (fp == NULL) {
        return -1;
    }
    
    if (fgets(username, size, fp) == NULL) {
        pclose(fp);
        return -1;
    }
    
    pclose(fp);
    
    // Remove trailing newline/carriage return
    char *newline = strchr(username, '\n');
    if (newline) *newline = '\0';
    char *carriage = strchr(username, '\r');
    if (carriage) *carriage = '\0';
    
    return 0;
}

// Function to convert Windows path to WSL mount path
void convert_windows_path_to_wsl(const char *win_path, char *wsl_path, size_t size) {
    if (strlen(win_path) >= 2 && win_path[1] == ':') {
        // Absolute Windows path (e.g., C:\path)
        char drive = tolower(win_path[0]);
        const char *path_part = win_path + 2;
        
        // Skip leading slash if present
        if (path_part[0] == '/' || path_part[0] == '\\') {
            path_part++;
        }
        
        snprintf(wsl_path, size, "/mnt/%c/%s", drive, path_part);
        
        // Convert backslashes to forward slashes
        for (char *p = wsl_path; *p; p++) {
            if (*p == '\\') *p = '/';
        }
    } else {
        // Relative path, assume it's relative to Windows user directory
        char username[256];
        if (get_windows_username(username, sizeof(username)) == 0) {
            snprintf(wsl_path, size, "/mnt/c/Users/%s/%s", username, win_path);
        } else {
            fprintf(stderr, "Error: Could not fetch Windows username.\n");
            exit(1);
        }
    }
} 