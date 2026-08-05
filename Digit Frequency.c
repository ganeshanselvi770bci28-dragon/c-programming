#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[1001];
    int frequencies[10] = {0};
    
    scanf("%s", s);
    
  
    for(int i = 0; i < strlen(s); i++) {
        if(isdigit(s[i])) {
            frequencies[s[i] - '0']++;
        }
    }
    
 
    for(int i = 0; i < 10; i++) {
        printf("%d ", frequencies[i]);
    }
    
    return 0;
}
