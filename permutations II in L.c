#include <stdlib.h>
#include <stdbool.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void backtrack(int* nums, int numsSize, int** result, int* returnSize, int** returnColumnSizes, int* current, bool* used, int depth) {
    if (depth == numsSize) {
        result[*returnSize] = (int*)malloc(numsSize * sizeof(int));
        for (int i = 0; i < numsSize; i++) {
            result[*returnSize][i] = current[i];
        }
        (*returnColumnSizes)[*returnSize] = numsSize;
        (*returnSize)++;
        return;
    }
    
    for (int i = 0; i < numsSize; i++) {
        if (used[i]) {
            continue;
        }
        if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
            continue;
        }
        
        used[i] = true;
        current[depth] = nums[i];
        backtrack(nums, numsSize, result, returnSize, returnColumnSizes, current, used, depth + 1);
        used[i] = false;
    }
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compare);
    
    int max_permutations = 1;
    for (int i = 1; i <= numsSize; i++) {
        max_permutations *= i;
    }
    
    int** result = (int**)malloc(max_permutations * sizeof(int*));
    *returnColumnSizes = (int*)malloc(max_permutations * sizeof(int));
    *returnSize = 0;
    
    int* current = (int*)malloc(numsSize * sizeof(int));
    bool* used = (bool*)calloc(numsSize, sizeof(bool));
    
    backtrack(nums, numsSize, result, returnSize, returnColumnSizes, current, used, 0);
    
    free(current);
    free(used);
    
    return result;
}
