#include <stdlib.h>

int compare(const void* a, const void* b) {
    int val_a = *(const int*)a;
    int val_b = *(const int*)b;
    if (val_a < val_b) return -1;
    if (val_a > val_b) return 1;
    return 0;
}

int findContentChildren(int* g, int gSize, int* s, int sSize) {
    qsort(g, gSize, sizeof(int), compare);
    qsort(s, sSize, sizeof(int), compare);
    
    int child = 0;
    int cookie = 0;
    
    while (child < gSize && cookie < sSize) {
        if (s[cookie] >= g[child]) {
            child++;
        }
        cookie++;
    }
    
    return child;
}
