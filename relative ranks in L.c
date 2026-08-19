#include <stdlib.h>
#include <stdio.h>

struct Athlete {
    int score;
    int index;
};

int compare(const void* a, const void* b) {
    int score_a = ((struct Athlete*)a)->score;
    int score_b = ((struct Athlete*)b)->score;
    if (score_a < score_b) return 1;
    if (score_a > score_b) return -1;
    return 0;
}

char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {
    struct Athlete* athletes = (struct Athlete*)malloc(scoreSize * sizeof(struct Athlete));
    
    for (int i = 0; i < scoreSize; i++) {
        athletes[i].score = score[i];
        athletes[i].index = i;
    }
    
    qsort(athletes, scoreSize, sizeof(struct Athlete), compare);
    
    char** result = (char**)malloc(scoreSize * sizeof(char*));
    
    for (int i = 0; i < scoreSize; i++) {
        int original_index = athletes[i].index;
        result[original_index] = (char*)malloc(13 * sizeof(char));
        
        if (i == 0) {
            sprintf(result[original_index], "Gold Medal");
        } else if (i == 1) {
            sprintf(result[original_index], "Silver Medal");
        } else if (i == 2) {
            sprintf(result[original_index], "Bronze Medal");
        } else {
            sprintf(result[original_index], "%d", i + 1);
        }
    }
    
    free(athletes);
    *returnSize = scoreSize;
    return result;
}
