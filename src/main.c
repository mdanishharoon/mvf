#include "mvf.h"

void print_usage(void) {
    printf("Usage:\n");
    printf("  mvf to-wsl <windows_path> <wsl_destination>\n");
    printf("  mvf to-win <wsl_path> <windows_destination>\n");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage();
        return 1;
    }
    
    if (strcmp(argv[1], "to-wsl") == 0) {
        return move_to_wsl(argv[2], argv[3]);
    } else if (strcmp(argv[1], "to-win") == 0) {
        return move_to_win(argv[2], argv[3]);
    } else {
        fprintf(stderr, "Invalid option: %s\n", argv[1]);
        print_usage();
        return 1;
    }
} 