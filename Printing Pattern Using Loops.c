#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n;
    scanf("%d", &n);
      
    // The total size of the grid grid will be (2*n - 1) by (2*n - 1)
    int len = 2 * n - 1;

    // Loop through each row
    for (int r = 0; r < len; r++) {
        // Loop through each column
        for (int c = 0; c < len; c++) {
            // Find the minimum distance of the current cell to any of the 4 edges
            int min_dist = r < c ? r : c;
            min_dist = min_dist < (len - 1 - r) ? min_dist : (len - 1 - r);
            min_dist = min_dist < (len - 1 - c) ? min_dist : (len - 1 - c);

            // The value at the current position decreases by the distance from the edge
            printf("%d ", n - min_dist);
        }
        // Move to the next line after completing a row
        printf("\n");
    }

    return 0;
}
