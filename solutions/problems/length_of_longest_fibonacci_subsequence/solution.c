// Binary search หา index ของ target ใน arr
int binarySearch(int* arr, int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;  // ไม่พบ
}

int lenLongestFibSubseq(int* arr, int arrSize) {
    int maxVal = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > maxVal) maxVal = arr[i];
    }
    
    // dp[j][i] ขนาด N*N = ความยาวของลำดับ Fibonacci ที่ลงท้ายด้วย A[j] และ A[i] 
    int** dp = (int**)malloc(arrSize * sizeof(int*));
    for (int i = 0; i < arrSize; i++) {
        dp[i] = (int*)malloc(arrSize * sizeof(int));
        for (int j = 0; j < arrSize; j++) {
            dp[i][j] = 2; // ความยาวเริ่มต้น 2
        }
    }
    
    int maxLen = 0;
    
    for (int i = 2; i < arrSize; i++) { // เริ่มดูที่ตัวที่สามเป็นต้นไป
        for (int j = i - 1; j >= 0; j--) {
            int target = arr[i] - arr[j]; // prev2 = new - prev1
            if (target >= arr[j]) break;
            int k = binarySearch(arr, 0, j - 1, target);
            if (target <= maxVal && k != -1) {
                dp[j][i] = dp[k][j] + 1; // ต่อลำดับเป็น arr[k], arr[j], arr[i]
                if (dp[j][i] > maxLen) {
                    maxLen = dp[j][i];
                }
            }
        }
    }
    
    // คืน memory
    for (int i = 0; i < arrSize; i++) free(dp[i]);
    free(dp);
    
    return maxLen > 2 ? maxLen : 0;
}