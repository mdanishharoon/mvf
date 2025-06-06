#include "mvf.h"

// Function to create directories recursively
int create_directory_recursive(const char *path) {
    char temp[MAX_PATH];
    char *p = NULL;
    size_t len;
    
    snprintf(temp, sizeof(temp), "%s", path);
    len = strlen(temp);
    
    if (temp[len - 1] == '/') {
        temp[len - 1] = 0;
    }
    
    for (p = temp + 1; *p; p++) {
        if (*p == '/') {
            *p = 0;
            if (mkdir(temp, 0755) != 0 && errno != EEXIST) {
                return -1;
            }
            *p = '/';
        }
    }
    
    if (mkdir(temp, 0755) != 0 && errno != EEXIST) {
        return -1;
    }
    
    return 0;
}

// Function to check if a file/directory exists
int file_exists(const char *path) {
    struct stat st;
    return stat(path, &st) == 0;
}

// Function to execute a command and return its status
int execute_command(const char *command) {
    int status = system(command);
    return WEXITSTATUS(status);
} 