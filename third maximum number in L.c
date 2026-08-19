#include <limits.h>
#include <stdbool.h>

int thirdMax(int* nums, int numsSize) {
    long long first = LLONG_MIN;
    long long second = LLONG_MIN;
    long long third = LLONG_MIN;
    
    for (int i = 0; i < numsSize; i++) {
        long long current = nums[i];
        
        if (current == first || current == second || current == third) {
            continue;
        }
        
        if (current > first) {
            third = second;
            second = first;
            first = current;
        } else if (current > second) {
            third = second;
            second = current;
        } else if (current > third) {
            third = current;
        }
    }
    
    if (third == LLONG_MIN) {
        return (int)first;
    }
    
    return (int)third;
}
