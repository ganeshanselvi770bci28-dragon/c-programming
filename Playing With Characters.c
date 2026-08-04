#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char ch;
    char s[100];
    char sen[100];

    // Read a single character
    scanf("%c", &ch);
    
    // Read a single word/string
    scanf("%s", s);
    
    // Clear the leftover newline from the previous buffer and read the full sentence
    scanf("\n");
    scanf("%[^\n]%*c", sen);
    
    // Print the outputs on separate lines
    printf("%c\n", ch);
    printf("%s\n", s);
    printf("%s\n", sen);
    
    return 0;
}
