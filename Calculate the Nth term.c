#include <stdio.h>

int find_nth_term(int n, int a, int b, int c) {
    if (n == 1) {
        return a;
    }
    if (n == 2) {
        return b;
    }
    if (n == 3) {
        return c;
    }
    return find_nth_term(n - 1, a, b, c) + find_nth_term(n - 2, a, b, c) + find_nth_term(n - 3, a, b, c);
}

int main() {
    int n, a, b, c;
    
    if (scanf("%d", &n) != 1) {
        return 1;
    }
    if (scanf("%d %d %d", &a, &b, &c) != 3) {
        return 1;
    }
    
    int ans = find_nth_term(n, a, b, c);
    printf("%d\n", ans);
    
    return 0;
}
