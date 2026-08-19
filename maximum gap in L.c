#include <stdlib.h>
#include <limits.h>

int maximumGap(int* nums, int numsSize) {
    if (numsSize < 2) {
        return 0;
    }
    
    int min_val = INT_MAX;
    int max_val = INT_MIN;
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < min_val) {
            min_val = nums[i];
        }
        if (nums[i] > max_val) {
            max_val = nums[i];
        }
    }
    
    if (min_val == max_val) {
        return 0;
    }
    
    int bucket_size = (max_val - min_val) / (numsSize - 1);
    if (bucket_size == 0) {
        bucket_size = 1;
    }
    
    int num_buckets = (max_val - min_val) / bucket_size + 1;
    
    int* bucket_mins = (int*)malloc(num_buckets * sizeof(int));
    int* bucket_maxs = (int*)malloc(num_buckets * sizeof(int));
    
    for (int i = 0; i < num_buckets; i++) {
        bucket_mins[i] = INT_MAX;
        bucket_maxs[i] = INT_MIN;
    }
    
    for (int i = 0; i < numsSize; i++) {
        int idx = (nums[i] - min_val) / bucket_size;
        if (nums[i] < bucket_mins[idx]) {
            bucket_mins[idx] = nums[i];
        }
        if (nums[i] > bucket_maxs[idx]) {
            bucket_maxs[idx] = nums[i];
        }
    }
    
    int max_gap = 0;
    int previous_max = max_val;
    
    for (int i = 0; i < num_buckets; i++) {
        if (bucket_mins[i] == INT_MAX) {
            continue;
        }
        if (previous_max != max_val) {
            int gap = bucket_mins[i] - previous_max;
            if (gap > max_gap) {
                max_gap = gap;
            }
        }
        previous_max = bucket_maxs[i];
    }
    
    free(bucket_mins);
    free(bucket_maxs);
    
    return max_gap;
}
