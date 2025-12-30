/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define HASH_SIZE 1000003  // จำนวนเฉพาะใหญ่ๆ
#define MAX_BITS 7

// ฟังก์ชันนับ bits
int popcount(int x) {
    int count = 0;
    while (x) {
        count += x & 1;
        x >>= 1;
    }
    return count;
}

int* findNumOfValidWords(char** words, int wordsSize, char** puzzles, int puzzlesSize, int* returnSize) {
    // Hash table: key = mask, value = frequency
    int* hashKeys = (int*)malloc(HASH_SIZE * sizeof(int));
    int* hashVals = (int*)calloc(HASH_SIZE, sizeof(int));
    
    // ค่าเริ่มค้น
    for (int i = 0; i < HASH_SIZE; i++) {
        hashKeys[i] = -1;
    }
    
    // word
    for (int i = 0; i < wordsSize; i++) {
        int mask = 0;
        char* word = words[i];
        
        // mask word
        for (int j = 0; word[j] != '\0'; j++) {
            mask |= 1 << (word[j] - 'a');
        }
        
        // เก็บ masks ที่มี 1 ≤ 7 bits
        if (popcount(mask) <= MAX_BITS) {
            int idx = mask % HASH_SIZE;
            if (idx < 0) idx += HASH_SIZE;  // handle negative
            
            // Linear probing
            while (hashKeys[idx] != -1 && hashKeys[idx] != mask) {
                idx = (idx + 1) % HASH_SIZE;
            }
            
            if (hashKeys[idx] == -1) {
                hashKeys[idx] = mask;
                hashVals[idx] = 1;
            } else {
                hashVals[idx]++;
            }
        }
    }
    
    int* result = (int*)malloc(puzzlesSize * sizeof(int));
    
    // puzzle
    for (int pi = 0; pi < puzzlesSize; pi++) {
        char* puzzle = puzzles[pi];
        int firstBit = 1 << (puzzle[0] - 'a');
        int puzzleMask = 0;
        
        // Create puzzle mask
        for (int i = 0; i < 7; i++) {
            puzzleMask |= 1 << (puzzle[i] - 'a');
        }
        
        int count = 0;
        int subset = puzzleMask;
        
        while (1) {
            // ตรวจก่อนว่ามีตัวอักษรตัวแรกไหม
            if (subset & firstBit) {
                int idx = subset % HASH_SIZE;
                if (idx < 0) idx += HASH_SIZE;
                
                while (hashKeys[idx] != -1) {
                    if (hashKeys[idx] == subset) {
                        count += hashVals[idx];
                        break;
                    }
                    idx = (idx + 1) % HASH_SIZE;
                }
            }
            
            if (subset == 0) break;
            subset = (subset - 1) & puzzleMask;
        }
        
        result[pi] = count;
    }
    
    free(hashKeys);
    free(hashVals);
    *returnSize = puzzlesSize;
    return result;
}