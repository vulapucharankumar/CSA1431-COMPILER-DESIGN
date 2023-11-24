#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isComment(const char *line) {
    if (strncmp(line, "//", 2) == 0) {
        return true;
    }
    if (strncmp(line, "/*", 2) == 0) {
        if (strstr(line, "*/") != NULL) {
            return true;
        }
        return false;
    }

    return false; 
}

int main() {
    char code[1000];
    printf("Enter a line of code: ");
    fgets(code, sizeof(code), stdin);
    code[strcspn(code, "\n")] = '\0';
    if (isComment(code)) {
        printf("The given line is a comment.\n");
    } else {
        printf("The given line is not a comment.\n");
    }

    return 0;
}