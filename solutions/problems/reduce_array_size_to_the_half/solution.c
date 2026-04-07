// ฟังก์ชันเปรียบเทียบสำหรับ qsort (เรียงจากมากไปน้อย)
int cmp(const void* a, const void* b) {
    return *(int*)b - *(int*)a;
}

int minSetSize(int* arr, int arrSize) {
    // หาค่าสูงสุดใน arr เพื่อกำหนดขนาด hash table
    int maxVal = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > maxVal) maxVal = arr[i];
    }
    
    // นับความถี่
    int* freq = (int*)calloc(maxVal + 1, sizeof(int));
    for (int i = 0; i < arrSize; i++) {
        freq[arr[i]]++;
    }
    
    // รวบรวมความถี่ที่มีค่า > 0
    int* frequencies = (int*)malloc(arrSize * sizeof(int));
    int freqCount = 0;
    for (int i = 0; i <= maxVal; i++) {
        if (freq[i] > 0) {
            frequencies[freqCount++] = freq[i];
        }
    }
    
    // เรียงความถี่จากมากไปน้อย
    qsort(frequencies, freqCount, sizeof(int), cmp);
    
    int target = arrSize / 2;
    int sum = 0;
    int result = 0;
    
    for (int i = 0; i < freqCount && sum < target; i++) {
        sum += frequencies[i];
        result++;
    }
    
    free(freq);
    free(frequencies);
    
    return result;
}