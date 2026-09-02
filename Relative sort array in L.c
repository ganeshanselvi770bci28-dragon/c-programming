int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize) {
    int count[1001];
    for (int i = 0; i <= 1000; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < arr1Size; i++) {
        count[arr1[i]]++;
    }

    int* result = (int*)malloc(arr1Size * sizeof(int));
    *returnSize = arr1Size;
    int idx = 0;

    for (int i = 0; i < arr2Size; i++) {
        int element = arr2[i];
        while (count[element] > 0) {
            result[idx++] = element;
            count[element]--;
        }
    }

    int remaining_start = idx;
    for (int i = 0; i <= 1000; i++) {
        while (count[i] > 0) {
            result[idx++] = i;
            count[i]--;
        }
    }

    return result;
}
