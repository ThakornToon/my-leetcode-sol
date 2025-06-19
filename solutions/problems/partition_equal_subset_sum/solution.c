bool canPartition(int* nums, int numsSize) {
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    if (sum % 2 != 0) {
        return false;
    }
    int target = sum / 2;
    int* dp = (int*)calloc(target + 1, sizeof(int)); // ดูว่าสร้างเลขนั้นๆได้ไหม
    dp[0] = 1;
    for (int it = 0; it < numsSize; it++) {
        int num = nums[it];
        for (int i = target; i - num >= 0; i--) {
            if (dp[i - num] == 1) {
                dp[i] = 1;
            }
        }
    }
    bool res = (bool)dp[target];
    free(dp);
    return res;
}