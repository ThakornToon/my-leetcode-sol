/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
    int num;
    int freq;
} NumFreq;

int compare(const void* a, const void* b) {
    return ((NumFreq*)b)->freq - ((NumFreq*)a)->freq;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    int min = nums[0], max = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < min) min = nums[i];
        if (nums[i] > max) max = nums[i];
    }
    
    int range = max - min + 1;
    int* freq = calloc(range, sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        freq[nums[i] - min]++;
    }
    
    NumFreq* numFreqs = malloc(range * sizeof(NumFreq));
    int count = 0;
    for (int i = 0; i < range; i++) {
        if (freq[i] > 0) {
            numFreqs[count].num = i + min;
            numFreqs[count].freq = freq[i];
            count++;
        }
    }
    free(freq);

    qsort(numFreqs, count, sizeof(NumFreq), compare);
    
    int* result = malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        result[i] = numFreqs[i].num;
    }
    
    free(numFreqs);
    *returnSize = k;
    return result;
}