int findNumberOfLIS(int* nums, int numsSize) {
    int* dp = (int*)malloc(numsSize * sizeof(int)); // เก็บความยาวลำดับ
    int* count = (int*)malloc(numsSize * sizeof(int)); // เก็บจำนวนลำดับ
    
    int max_len = 1;
    int result = 0;
    // พิจารณาตัวที่ i ไปต่อท้ายลำดับจากตัวก่อนหน้า j 
    for (int i = 0; i < numsSize; i++) {
        dp[i] = 1;
        count[i] = 1; // กรณีมีแค่ตัวนั้นในลำดับ
        
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                if (dp[j] + 1 > dp[i]) { // ลองเอาไปต่อว่าจะยาวมากกว่าไหม
                    dp[i] = dp[j] + 1;
                    count[i] = count[j];
                } else if (dp[j] + 1 == dp[i]) {
                    count[i] += count[j];
                }
            }
        }
        
        if (dp[i] > max_len) {
            max_len = dp[i];
            result = count[i];
        } else if (dp[i] == max_len) {
            // 122 -> 12, 12
            result += count[i];
        }
    }
    
    free(dp);
    free(count);
    return result;
}