int getWinner(int* arr, int arrSize, int k) {
    // กรณี k มากพอ ค่าสูงสุดจะชนะแน่นอน
    if (k >= arrSize - 1) {
        int maxVal = arr[0];
        for (int i = 1; i < arrSize; i++) {
            if (arr[i] > maxVal) {
                maxVal = arr[i];
            }
        }
        return maxVal;
    }
    
    int current = arr[0];  // ผู้ชนะปัจจุบัน
    int winCount = 0;
    
    for (int i = 1; i < arrSize; i++) {
        if (current > arr[i]) {
            winCount++;
        } else {
            current = arr[i];
            winCount = 1;
        }
        
        if (winCount == k) {
            return current;
        }
    }
    
    // ถ้า loop จบโดยไม่ return แสดงว่า current คือค่าสูงสุด
    return current;
}