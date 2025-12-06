/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* fairCandySwap(int* aliceSizes, int aliceSizesSize, int* bobSizes, int bobSizesSize, int* returnSize) {
    // sumA - x + y = sumB - y + x
    // y = x - (sumA - sumB) / 2
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    
    // คำนวณผลรวม
    int sumA = 0, sumB = 0;
    for (int i = 0; i < aliceSizesSize; i++) sumA += aliceSizes[i];
    for (int i = 0; i < bobSizesSize; i++) sumB += bobSizes[i];
    
    int diff = (sumA - sumB) / 2;
    
    // สร้างเซ็ตสำหรับ Bob (ใช้การค้นหาแบบบูลีน)
    int maxSize = 100001;
    int* bobSet = (int*)calloc(maxSize, sizeof(int));
    
    for (int i = 0; i < bobSizesSize; i++) {
        bobSet[bobSizes[i]] = 1;
    }
    
    // หาคู่ที่ตรงกัน
    for (int i = 0; i < aliceSizesSize; i++) {
        int y = aliceSizes[i] - diff;
        if (y >= 1 && y < maxSize && bobSet[y]) {
            result[0] = aliceSizes[i];
            result[1] = y;
            free(bobSet);
            return result;
        }
    }
    
    free(bobSet);
    return result;
}