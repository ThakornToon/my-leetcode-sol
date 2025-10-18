bool splitArraySameAverage(int* nums, int numsSize) {
    int total = 0;
    for (int i = 0; i < numsSize; i++) {
        total += nums[i];
    }
    
    // ตรวจสอบความเป็นไปได้ทางคณิตศาสตร์
    bool possible = false;
    for (int k = 1; k <= numsSize / 2; k++) {
        if (k * total % numsSize == 0) {
            possible = true;
            break;
        }
    }
    if (!possible) return false;
    
    // DP ด้วย bitset (ใช้ array แทน)
    int maxSum = total + 1;
    bool dp[31][300001] = {false}; // dp[k][sum]
    dp[0][0] = true;
    
    for (int i = 0; i < numsSize; i++) {
        for (int k = numsSize / 2; k >= 1; k--) {
            for (int s = maxSum - 1; s >= nums[i]; s--) {
                if (dp[k-1][s - nums[i]]) {
                    dp[k][s] = true;
                }
            }
        }
    }
    
    // ตรวจสอบผลลัพธ์
    for (int k = 1; k <= numsSize / 2; k++) {
        if (k * total % numsSize == 0) {
            int target = k * total / numsSize;
            if (dp[k][target]) {
                return true;
            }
        }
    }
    
    return false;
}