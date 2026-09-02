int compare(const void* a, const void* b) {
    char s1[24];
    char s2[24];
    
    char comb1[48];
    char comb2[48];
    
    sprintf(s1, "%d", *(int*)a);
    sprintf(s2, "%d", *(int*)b);
    
    int i = 0, j = 0;
    while (s1[i] != '\0') {
        comb1[i] = s1[i];
        i++;
    }
    while (s2[j] != '\0') {
        comb1[i + j] = s2[j];
        j++;
    }
    comb1[i + j] = '\0';
    
    i = 0; j = 0;
    while (s2[i] != '\0') {
        comb2[i] = s2[i];
        i++;
    }
    while (s1[j] != '\0') {
        comb2[i + j] = s1[j];
        j++;
    }
    comb2[i + j] = '\0';
    
    int idx = 0;
    while (comb1[idx] != '\0' && comb2[idx] != '\0') {
        if (comb1[idx] != comb2[idx]) {
            return (comb2[idx] - comb1[idx]);
        }
        idx++;
    }
    return 0;
}

char* largestNumber(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    
    if (nums[0] == 0) {
        char* zero_res = (char*)malloc(2 * sizeof(char));
        zero_res[0] = '0';
        zero_res[1] = '\0';
        return zero_res;
    }
    
    char* result = (char*)malloc(numsSize * 12 * sizeof(char));
    result[0] = '\0';
    
    int total_len = 0;
    for (int i = 0; i < numsSize; i++) {
        char temp[24];
        sprintf(temp, "%d", nums[i]);
        
        int j = 0;
        while (temp[j] != '\0') {
            result[total_len++] = temp[j++];
        }
    }
    result[total_len] = '\0';
    
    return result;
}
