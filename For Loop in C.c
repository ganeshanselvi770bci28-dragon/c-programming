#include <stdio.h>

int main() {
    int a, b;
    
    // Read the interval boundaries [a, b]
    if (scanf("%d\n%d", &a, &b) != 2) {
        return 1;
    }
    
    // Loop through each integer in the interval
    for (int i = a; i <= b; i++) {
        if (i >= 1 && i <= 9) {
            // Print the lowercase English representation for numbers 1 to 9
            if (i == 1) printf("one\n");
            else if (i == 2) printf("two\n");
            else if (i == 3) printf("three\n");
            else if (i == 4) printf("four\n");
            else if (i == 5) printf("five\n");
            else if (i == 6) printf("six\n");
            else if (i == 7) printf("seven\n");
            else if (i == 8) printf("eight\n");
            else if (i == 9) printf("nine\n");
        } else if (i > 9) {
            // Check parity for numbers greater than 9
            if (i % 2 == 0) {
                printf("even\n");
            } else {
                printf("odd\n");
            }
        }
    }
    
    return 0;
}
