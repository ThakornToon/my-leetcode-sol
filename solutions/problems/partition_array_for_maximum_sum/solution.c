int maxSumAfterPartitioning(int* arr, int arrSize, int k) {
    // dp[i] เก็บค่ามากสุดของลำดับยาว 0 ถึง i
    int* dp = (int*)calloc(arrSize + 1, sizeof(int));
    
    for (int i = 1; i <= arrSize; i++) {
        int currentMax = 0;
        
        // ลองความยาวของส่วนสุดท้ายจาก 1 ถึง k
        for (int j = 1; j <= k && j <= i; j++) {
            // หาค่าสูงสุดในส่วนสุดท้ายยาว j
            if (arr[i - j] > currentMax) {
                currentMax = arr[i - j];
            }
            
            // คำนวณผลรวม
            int candidate = dp[i - j] + currentMax * j;
            if (candidate > dp[i]) {
                dp[i] = candidate;
            }
        }
    }
    
    int result = dp[arrSize];
    free(dp);
    return result;
}