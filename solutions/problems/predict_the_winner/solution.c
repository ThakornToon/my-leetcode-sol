int max(int a, int b) {
    return (a >= b) ? a : b;
}

bool predictTheWinner(int* nums, int numsSize) {
    // dp[i][j] ผลต่าง P1 - P2 เมื่อพิจารณาตำแหน่ง i ถึง j ด้วยการเลือกที่ดีที่สุดทั้งสองฝ่าย
    int** dp = (int**)malloc(numsSize * sizeof(int*));
    for (int i = 0; i < numsSize; i++) {
        dp[i] = (int*)calloc(numsSize, sizeof(int));
        dp[i][i] = nums[i];
    }

    for (int len = 2; len <= numsSize; len++) {
        for (int i = 0; i <= numsSize - len; i++) {
            int j = i + len - 1;
            // เมื่อพิจารณา i ถึง j เริ่มที่ P1 เราจะเลือกตัวแรกหรือตัวสุดท้ายก่อน จากนั้นเป็นตาของ P2 
            dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
        }
    }
    return dp[0][numsSize - 1] >= 0;
}