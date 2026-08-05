#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) {
        return 1;
    }
    
    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        return 1;
    }
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) == 1) {
            sum += arr[i];
        }
    }
    
    printf("%d\n", sum);
    
    free(arr);
    return 0;
}
