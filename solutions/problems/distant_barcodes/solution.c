/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rearrangeBarcodes(int* barcodes, int barcodesSize, int* returnSize) {
    *returnSize = barcodesSize;
    int* result = (int*)malloc(barcodesSize * sizeof(int));
    
    // นับความถี่
    int freq[10001] = {0};
    int maxFreq = 0, maxVal = 0;
    
    for (int i = 0; i < barcodesSize; i++) {
        freq[barcodes[i]]++;
        if (freq[barcodes[i]] > maxFreq) {
            maxFreq = freq[barcodes[i]];
            maxVal = barcodes[i];
        }
    }
    
    // ตรวจสอบความถี่ที่มากที่สุด
    if (maxFreq > (barcodesSize + 1) / 2) {
        *returnSize = 0;
        free(result);
        return NULL;
    }
    
    // ความถี่มากเราใส่ใน index คู่
    int idx = 0;
    while (freq[maxVal] > 0) {
        result[idx] = maxVal;
        freq[maxVal]--;
        idx += 2;
    }
    
    if (idx >= barcodesSize) idx = 1; 

    for (int i = 1; i <= 10000; i++) {
        while (freq[i] > 0) {
            if (idx >= barcodesSize) idx = 1;  // ตำแหน่งคู่เต็มแล้ว
            result[idx] = i;
            freq[i]--;
            idx += 2;
        }
    }
    
    return result;
}