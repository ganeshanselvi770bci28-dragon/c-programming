#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 200003 // A prime number larger than 2 * numsSize for low collisions

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

typedef struct {
    Node* buckets[HASH_SIZE];
} HashMap;

// Hash function using basic modulo
int hash(int key) {
    int h = key % HASH_SIZE;
    if (h < 0) h += HASH_SIZE;
    return h;
}

// Insert or update frequency, returns the new frequency
int increment_and_get(HashMap* map, int key) {
    int idx = hash(key);
    Node* curr = map->buckets[idx];
    while (curr != NULL) {
        if (curr->key == key) {
            curr->value++;
            return curr->value;
        }
        curr = curr->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = 1;
    newNode->next = map->buckets[idx];
    map->buckets[idx] = newNode;
    return 1;
}

// Decrease frequency of an element
void decrement(HashMap* map, int key) {
    int idx = hash(key);
    Node* curr = map->buckets[idx];
    while (curr != NULL) {
        if (curr->key == key) {
            curr->value--;
            return;
        }
        curr = curr->next;
    }
}

// Free memory allocated for the hash map
void freeMap(HashMap* map) {
    for (int i = 0; i < HASH_SIZE; i++) {
        Node* curr = map->buckets[i];
        while (curr != NULL) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
}

int maxSubarrayLength(int* nums, int numsSize, int k) {
    HashMap* map = (HashMap*)calloc(1, sizeof(HashMap));
    int left = 0;
    int max_len = 0;

    for (int right = 0; right < numsSize; right++) {
        // Expand window and update element count
        int freq = increment_and_get(map, nums[right]);

        // Shrink window from the left until condition is valid
        while (freq > k) {
            decrement(map, nums[left]);
            if (nums[left] == nums[right]) {
                freq--;
            }
            left++;
        }

        // Calculate max window size
        int current_len = right - left + 1;
        if (current_len > max_len) {
            max_len = current_len;
        }
    }

    freeMap(map);
    free(map);
    return max_len;
}
