/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
    int index;
    int score;
} Player;

int compare(const void* a, const void* b) {
    return ((Player*)b)->score - ((Player*)a)->score;
}

char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {
    *returnSize = scoreSize;
    Player* players = malloc(scoreSize * sizeof(Player));
    for (int i = 0; i < scoreSize; i++) {
        players[i].index = i;
        players[i].score = score[i];
    }
    
    qsort(players, scoreSize, sizeof(Player), compare);
    
    char** result = malloc(scoreSize * sizeof(char*));
    for (int i = 0; i < scoreSize; i++) {
        if (i == 0) {
            result[players[i].index] = strdup("Gold Medal");
        } else if (i == 1) {
            result[players[i].index] = strdup("Silver Medal");
        } else if (i == 2) {
            result[players[i].index] = strdup("Bronze Medal");
        } else {
            char* rank = malloc(7 * sizeof(char));
            sprintf(rank, "%d", i + 1);
            result[players[i].index] = rank;
        }
    }
    
    free(players);
    return result;
}