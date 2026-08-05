#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 1. Sorts strings in alphabetical order
int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a, b);
}

// 2. Sorts strings in reverse alphabetical order
int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b, a);
}

// Helper function to count distinct characters in a string
int count_distinct(const char* str) {
    int hash[26] = {0}; // Assumes lowercase English alphabets based on standard problem constraints
    int distinct_count = 0;
    
    while (*str) {
        int index = *str - 'a';
        if (hash[index] == 0) {
            hash[index] = 1;
            distinct_count++;
        }
        str++;
    }
    return distinct_count;
}

// 3. Sorts by distinct characters count. Ties broken lexicographically.
int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int count_a = count_distinct(a);
    int count_b = count_distinct(b);
    
    if (count_a != count_b) {
        return count_a - count_b;
    }
    return strcmp(a, b);
}

// 4. Sorts by length. Ties broken lexicographically.
int sort_by_length(const char* a, const char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    
    if (len_a != len_b) {
        return len_a - len_b;
    }
    return strcmp(a, b);
}

// Stable sorting algorithm using the passed comparison function pointer
void string_sort(char** arr, const int len, int (*cmp_func)(const char* a, const char* b)) {
    // Using a simple Bubble Sort implementation
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (cmp_func(arr[j], arr[j + 1]) > 0) {
                // Swap the pointers to the strings
                char* temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}
