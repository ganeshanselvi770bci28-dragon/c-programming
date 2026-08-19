#include <stdlib.h>

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int counts[1001] = {0};
    
    for (int i = 0; i < nums1Size; i++) {
        counts[nums1[i]]++;
    }
    
    int max_possible_size = nums1Size < nums2Size ? nums1Size : nums2Size;
    int* result = (int*)malloc(max_possible_size * sizeof(int));
    int count = 0;
    
    for (int i = 0; i < nums2Size; i++) {
        int current = nums2[i];
        if (counts[current] > 0) {
            result[count++] = current;
            counts[current]--;
        }
    }
    
    *returnSize = count;
    return result;
}
