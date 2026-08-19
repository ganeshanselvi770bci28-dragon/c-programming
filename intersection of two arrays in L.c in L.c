#include <stdlib.h>
#include <stdbool.h>

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    bool lookup[1001] = {false};
    bool added[1001] = {false};
    
    for (int i = 0; i < nums1Size; i++) {
        lookup[nums1[i]] = true;
    }
    
    int max_possible_size = nums1Size < nums2Size ? nums1Size : nums2Size;
    int* result = (int*)malloc(max_possible_size * sizeof(int));
    int count = 0;
    
    for (int i = 0; i < nums2Size; i++) {
        int current = nums2[i];
        if (lookup[current] && !added[current]) {
            result[count++] = current;
            added[current] = true;
        }
    }
    
    *returnSize = count;
    return result;
}
