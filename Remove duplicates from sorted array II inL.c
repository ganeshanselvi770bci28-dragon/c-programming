int removeDuplicates(int* nums, int numsSize) {
   
    if (numsSize <= 2) {
        return numsSize;
    }
    
    int writeIndex = 2; 
    
    for (int i = 2; i < numsSize; i++) {
        if (nums[i] != nums[writeIndex - 2]) {
            nums[writeIndex] = nums[i];
            writeIndex++;
        }
    }
    
    return writeIndex;
}
