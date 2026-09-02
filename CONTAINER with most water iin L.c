int maxArea(int* height, int heightSize) {
    int max_water = 0;
    int left = 0;
    int right = heightSize - 1;

    while (left < right) {
        int h_left = height[left];
        int h_right = height[right];
        
        int current_height = h_left < h_right ? h_left : h_right;
        int current_width = right - left;
        int current_water = current_height * current_width;

        if (current_water > max_water) {
            max_water = current_water;
        }

        if (h_left < h_right) {
            left++;
        } else {
            right--;
        }
    }

    return max_water;
}
