#include <stdlib.h>
#include <string.h>

int compareChars(const void* a, const void* b) {
    return (*(char*)a - *(char*)b);
}

struct HashEntry {
    char sorted_key[101];
    int group_index;
    struct HashEntry* next;
};

unsigned int hash(char* str, int table_size) {
    unsigned int h = 5381;
    int c;
    while ((c = *str++)) {
        h = ((h << 5) + h) + c;
    }
    return h % table_size;
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    int table_size = strsSize * 2;
    struct HashEntry** hash_table = (struct HashEntry**)calloc(table_size, sizeof(struct HashEntry*));
    
    char*** groups = (char***)malloc(strsSize * sizeof(char**));
    *returnColumnSizes = (int*)malloc(strsSize * sizeof(int));
    int group_count = 0;
    
    for (int i = 0; i < strsSize; i++) {
        char sorted[101];
        strcpy(sorted, strs[i]);
        qsort(sorted, strlen(sorted), sizeof(char), compareChars);
        
        unsigned int slot = hash(sorted, table_size);
        struct HashEntry* entry = hash_table[slot];
        int target_group = -1;
        
        while (entry != NULL) {
            if (strcmp(entry->sorted_key, sorted) == 0) {
                target_group = entry->group_index;
                break;
            }
            entry = entry->next;
        }
        
        if (target_group == -1) {
            target_group = group_count;
            groups[target_group] = (char**)malloc(strsSize * sizeof(char*));
            (*returnColumnSizes)[target_group] = 0;
            group_count++;
            
            struct HashEntry* new_entry = (struct HashEntry*)malloc(sizeof(struct HashEntry));
            strcpy(new_entry->sorted_key, sorted);
            new_entry->group_index = target_group;
            new_entry->next = hash_table[slot];
            hash_table[slot] = new_entry;
        }
        
        int element_idx = (*returnColumnSizes)[target_group];
        groups[target_group][element_idx] = strs[i];
        (*returnColumnSizes)[target_group]++;
    }
    
    char*** final_result = (char***)malloc(group_count * sizeof(char**));
    int* final_columns = (int*)malloc(group_count * sizeof(int));
    
    for (int i = 0; i < group_count; i++) {
        int count = (*returnColumnSizes)[i];
        final_columns[i] = count;
        final_result[i] = (char**)malloc(count * sizeof(char*));
        for (int j = 0; j < count; j++) {
            final_result[i][j] = groups[i][j];
        }
        free(groups[i]);
    }
    
    free(groups);
    free(*returnColumnSizes);
    
    for (int i = 0; i < table_size; i++) {
        struct HashEntry* entry = hash_table[i];
        while (entry != NULL) {
            struct HashEntry* temp = entry;
            entry = entry->next;
            free(temp);
        }
    }
    free(hash_table);
    
    *returnSize = group_count;
    *returnColumnSizes = final_columns;
    return final_result;
}
