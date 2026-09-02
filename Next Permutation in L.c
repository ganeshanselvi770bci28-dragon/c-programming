void nextPermutation(int* nums, int numsSize) {
    if (numsSize <= 1) {
        return;
    }

    int i = numsSize - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    if (i >= 0) {
        int j = numsSize - 1;
        while (nums[j] <= nums[i]) {
            j--;
        }
        
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    int start = i + 1;
    int end = numsSize - 1;
    while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}
