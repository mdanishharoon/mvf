#ifndef MVF_H
#define MVF_H

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <ctype.h>

#define MAX_PATH 4096
#define MAX_COMMAND 16384

// Function declarations from utils.c
int create_directory_recursive(const char *path);
int file_exists(const char *path);
int execute_command(const char *command);

// Function declarations from windows.c
int get_windows_username(char *username, size_t size);
void convert_windows_path_to_wsl(const char *win_path, char *wsl_path, size_t size);

// Function declarations from transfer.c
int move_to_wsl(const char *win_path, const char *wsl_dest);
int move_to_win(const char *wsl_source, const char *win_dest);

// Function declarations from main.c
void print_usage(void);

#endif // MVF_H 