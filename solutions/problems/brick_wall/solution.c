#define MAX_SIZE 10000

typedef struct {
    long long key;
    int value;
} Pair;

int leastBricks(int** wall, int wallSize, int* wallColSize) {
    Pair hash[MAX_SIZE];
    int hashSize = 0;
    int maxCount = 0;
    
    for (int i = 0; i < wallSize; i++) {
        long long sum = 0;
        for (int j = 0; j < wallColSize[i] - 1; j++) {
            sum += wall[i][j];
            
            // Find or insert in hash
            int found = 0;
            for (int k = 0; k < hashSize; k++) {
                if (hash[k].key == sum) {
                    hash[k].value++;
                    if (hash[k].value > maxCount) {
                        maxCount = hash[k].value;
                    }
                    found = 1;
                    break;
                }
            }
            if (!found) {
                hash[hashSize].key = sum;
                hash[hashSize].value = 1;
                if (1 > maxCount) {
                    maxCount = 1;
                }
                hashSize++;
            }
        }
    }
    
    return wallSize - maxCount;
}