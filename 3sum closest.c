int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int abs_val(int val) {
    return val < 0 ? -val : val;
}

int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), compare);
    int closest_sum = nums[0] + nums[1] + nums[2];
    
    for (int i = 0; i < numsSize - 2; i++) {
        int left = i + 1;
        int right = numsSize - 1;
        
        while (left < right) {
            int current_sum = nums[i] + nums[left] + nums[right];
            
            if (current_sum == target) {
                return current_sum;
            }
            
            if (abs_val(current_sum - target) < abs_val(closest_sum - target)) {
                closest_sum = current_sum;
            }
            
            if (current_sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }
    
    return closest_sum;
}
