#include <stdio.h>
#include <stdlib.h>

// Helper function to compare intervals for qsort
int compareIntervals(const void *a, const void *b) {
    int *intervalA = *(int **)a;
    int *intervalB = *(int **)b;
    
    // Sort primarily by start time
    if (intervalA[0] != intervalB[0]) {
        return intervalA[0] - intervalB[0];
    }
    // If start times are equal, sort by end time
    return intervalA[1] - intervalB[1];
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *returnColumnSizes must be malloced, assume caller calls free().
 */
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    if (intervalsSize <= 0) {
        *returnSize = 0;
        return NULL;
    }

    // Step 1: Sort intervals by their start times
    qsort(intervals, intervalsSize, sizeof(int*), compareIntervals);

    // Step 2: Allocate memory for the merged results
    int** merged = (int**)malloc(intervalsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(intervalsSize * sizeof(int));
    
    int count = 0;
    
    // Insert the first interval to begin comparison
    merged[count] = (int*)malloc(2 * sizeof(int));
    merged[count][0] = intervals[0][0];
    merged[count][1] = intervals[0][1];
    (*returnColumnSizes)[count] = 2;
    count++;

    // Step 3: Iterate through intervals and merge overlaps
    for (int i = 1; i < intervalsSize; i++) {
        int currentStart = intervals[i][0];
        int currentEnd = intervals[i][1];
        int lastMergedEnd = merged[count - 1][1];

        // If current interval overlaps with the last merged interval
        if (currentStart <= lastMergedEnd) {
            // Update the end time of the last merged interval if needed
            if (currentEnd > lastMergedEnd) {
                merged[count - 1][1] = currentEnd;
            }
        } else {
            // No overlap, add current interval to the merged list
            merged[count] = (int*)malloc(2 * sizeof(int));
            merged[count][0] = currentStart;
            merged[count][1] = currentEnd;
            (*returnColumnSizes)[count] = 2;
            count++;
        }
    }

    *returnSize = count;
    return merged;
}
