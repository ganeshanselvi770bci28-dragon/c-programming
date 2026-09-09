#include <stdio.h>
#include <stdlib.h>

int largestRectangleArea(int* heights, int heightsSize) {
    // Stack stores indices of the histogram bars
    int* stack = (int*)malloc((heightsSize + 1) * sizeof(int));
    int top = -1;
    int max_area = 0;
    
    // Iterate through all bars plus one extra cycle to clear the stack
    for (int i = 0; i <= heightsSize; i++) {
        // Use a dummy height of 0 at the end to pop all remaining elements
        int current_height = (i == heightsSize) ? 0 : heights[i];
        
        // Maintain a strictly increasing stack of heights
        while (top != -1 && heights[stack[top]] >= current_height) {
            int height = heights[stack[top--]];
            
            // If the stack is empty, the popped bar was the shortest so far
            int width = (top == -1) ? i : (i - stack[top] - 1);
            
            int current_area = height * width;
            if (current_area > max_area) {
                max_area = current_area;
            }
        }
        // Push the current bar's index onto the stack
        stack[++top] = i;
    }
    
    free(stack);
    return max_area;
}
