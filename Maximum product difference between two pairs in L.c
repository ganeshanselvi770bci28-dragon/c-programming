int maxProductDifference(int* nums, int numsSize) {
    int max1 = 0;
    int max2 = 0;
    int min1 = 10001;
    int min2 = 10001;

    for (int i = 0; i < numsSize; i++) {
        int val = nums[i];

        if (val > max1) {
            max2 = max1;
            max1 = val;
        } else if (val > max2) {
            max2 = val;
        }

        if (val < min1) {
            min2 = min1;
            min1 = val;
        } else if (val < min2) {
            min2 = val;
        }
    }

    return (max1 * max2) - (min1 * min2);
}
