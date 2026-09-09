#include <stdio.h>
#include <stdlib.h>

// Helper function from the "Largest Rectangle in Histogram" problem
int largestRectangleArea(int* heights, int cols) {
    int* stack = (int*)malloc((cols + 1) * sizeof(int));
    int top = -1;
    int max_area = 0;
    
    for (int i = 0; i <= cols; i++) {
        int current_height = (i == cols) ? 0 : heights[i];
        
        while (top != -1 && heights[stack[top]] >= current_height) {
            int height = heights[stack[top--]];
            int width = (top == -1) ? i : (i - stack[top] - 1);
            int current_area = height * width;
            if (current_area > max_area) {
                max_area = current_area;
            }
        }
        stack[++top] = i;
    }
    
    free(stack);
    return max_area;
}

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0 || matrixColSize[0] == 0) return 0;
    
    int cols = matrixColSize[0];
    // heights array will track the consecutive '1's for each column
    int* heights = (int*)calloc(cols, sizeof(int));
    int max_rectangle = 0;
    
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < cols; j++) {
            // If it's '1', add to current column height; if '0', reset height to 0
            if (matrix[i][j] == '1') {
                heights[j] += 1;
            } else {
                heights[j] = 0;
            }
        }
        
        // Find the maximum area for the histogram formed up to row i
        int current_max = largestRectangleArea(heights, cols);
        if (current_max > max_rectangle) {
            max_rectangle = current_max;
        }
    }
    
    free(heights);
    return max_rectangle;
}
