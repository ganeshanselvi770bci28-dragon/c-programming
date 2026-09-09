#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int longestValidParentheses(char* s) {
    int n = strlen(s);
    if (n == 0) return 0;

    // Allocate memory for the stack (+1 to accommodate the base index -1)
    int* stack = (int*)malloc((n + 1) * sizeof(int));
    int top = -1;
    int max_len = 0;

    // Push the initial base index (-1) onto the stack
    stack[++top] = -1;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            stack[++top] = i; // Push the index of '('
        } else {
            top--; // Pop the top element
            
            if (top == -1) {
                // If stack becomes empty, push the current index as the new base
                stack[++top] = i;
            } else {
                // Calculate the length of the current valid substring
                max_len = MAX(max_len, i - stack[top]);
            }
        }
    }

    free(stack); // Free allocated memory
    return max_len;
}
