int findLucky(int* arr, int arrSize) {
    int freq[501] = {0};  // ตามโจทย์ arr[i] <= 500
    
    // นับความถี่
    for (int i = 0; i < arrSize; i++) {
        freq[arr[i]]++;
    }
    
    // หาค่ามากที่สุดที่ value == frequency
    int maxLucky = -1;
    for (int i = 1; i <= 500; i++) {
        if (freq[i] == i && i > maxLucky) {
            maxLucky = i;
        }
    }
    
    return maxLucky;
}