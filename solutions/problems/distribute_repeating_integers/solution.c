// ฟังก์ชันเปรียบเทียบสำหรับ qsort (เรียงจากมากไปน้อย)
int cmpDesc(const void* a, const void* b) {
    return *(int*)b - *(int*)a;
}

bool backtrack(int* freq, int freqSize, int* quantity, int quantitySize, int idx) {
    if (idx == quantitySize) {
        return true;
    }
    
    for (int i = 0; i < freqSize; i++) {
        if (freq[i] >= quantity[idx]) {
            freq[i] -= quantity[idx];
            if (backtrack(freq, freqSize, quantity, quantitySize, idx + 1)) {
                freq[i] += quantity[idx];
                return true;
            }
            freq[i] += quantity[idx];
        }
    }
    
    return false;
}

bool canDistribute(int* nums, int numsSize, int* quantity, int quantitySize) {
    int maxNum = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > maxNum) maxNum = nums[i];
    }
    
    int* count = (int*)calloc(maxNum + 1, sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        count[nums[i]]++;
    }
    
    // เก็บ freq ที่ >0
    int* freq = (int*)malloc(maxNum * sizeof(int));
    int freqSize = 0;
    for (int i = 0; i <= maxNum; i++) {
        if (count[i] > 0) {
            freq[freqSize++] = count[i];
        }
    }
    free(count);
    
    // เรียง quantity จากมากไปน้อย
    qsort(quantity, quantitySize, sizeof(int), cmpDesc);
    
    // optimization: ตัด freq ที่น้อยกว่า quantity ที่เล็กที่สุด
    int minQ = quantity[quantitySize - 1];
    int* newFreq = (int*)malloc(freqSize * sizeof(int));
    int newFreqSize = 0;
    for (int i = 0; i < freqSize; i++) {
        if (freq[i] >= minQ) {
            newFreq[newFreqSize++] = freq[i];
        }
    }
    free(freq);
    
    bool result = backtrack(newFreq, newFreqSize, quantity, quantitySize, 0);
    
    free(newFreq);
    return result;
}