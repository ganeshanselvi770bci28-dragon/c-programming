#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* simplifyPath(char* path) {
    int len = strlen(path);
    // Allocate space for the stack to store directory tokens
    char** stack = (char**)malloc(len * sizeof(char*));
    int top = 0;
    
    // Tokenize the path by the slash '/' delimiter
    char* token = strtok(path, "/");
    while (token != NULL) {
        if (strcmp(token, ".") == 0 || strcmp(token, "") == 0) {
            // A single period or empty token means current directory; do nothing
        } else if (strcmp(token, "..") == 0) {
            // A double period means pop the last directory if stack is not empty
            if (top > 0) {
                top--;
            }
        } else {
            // Valid directory name; push to stack
            stack[top++] = token;
        }
        token = strtok(NULL, "/");
    }
    
    // Allocate memory for the final canonical path result
    char* result = (char*)malloc((len + 1) * sizeof(char));
    result[0] = '\0'; // Start with an empty string
    
    // Reconstruct the path from the stack
    if (top == 0) {
        strcpy(result, "/");
    } else {
        for (int i = 0; i < top; i++) {
            strcat(result, "/");
            strcat(result, stack[i]);
        }
    }
    
    free(stack);
    return result;
}
