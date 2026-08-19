#include <string.h>

char findTheDifference(char* s, char* t) {
    char result = 0;
    int len_s = strlen(s);
    int len_t = strlen(t);
    
    for (int i = 0; i < len_s; i++) {
        result ^= s[i];
    }
    
    for (int i = 0; i < len_t; i++) {
        result ^= t[i];
    }
    
    return result;
}
