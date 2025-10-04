/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct {
    char* word;
    int freq;
} WordFreq;

// Comparison function for sorting
int compare(const void* a, const void* b) {
    WordFreq* w1 = (WordFreq*)a;
    WordFreq* w2 = (WordFreq*)b;
    
    // First by frequency (descending)
    if (w1->freq != w2->freq) {
        return w2->freq - w1->freq;
    }
    // Then by lexicographical order (ascending)
    return strcmp(w1->word, w2->word);
}

char** topKFrequent(char** words, int wordsSize, int k, int* returnSize) {
    *returnSize = k;
    
    // Count frequencies
    WordFreq* freqArr = (WordFreq*)malloc(wordsSize * sizeof(WordFreq));
    int uniqueCount = 0;
    
    for (int i = 0; i < wordsSize; i++) {
        int found = 0;
        for (int j = 0; j < uniqueCount; j++) {
            if (strcmp(words[i], freqArr[j].word) == 0) {
                freqArr[j].freq++;
                found = 1;
                break;
            }
        }
        if (!found) {
            freqArr[uniqueCount].word = words[i];
            freqArr[uniqueCount].freq = 1;
            uniqueCount++;
        }
    }
    
    // Sort by frequency and lexicographical order
    qsort(freqArr, uniqueCount, sizeof(WordFreq), compare);
    
    // Prepare result
    char** result = (char**)malloc(k * sizeof(char*));
    for (int i = 0; i < k; i++) {
        result[i] = (char*)malloc((strlen(freqArr[i].word) + 1) * sizeof(char));
        strcpy(result[i], freqArr[i].word);
    }
    
    free(freqArr);
    return result;
}