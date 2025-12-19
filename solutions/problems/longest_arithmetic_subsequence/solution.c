#define MAX_DIFF 500

int max(int a, int b) {
    return a > b ? a : b;
}

int longestArithSeqLength(int* nums, int numsSize) {
    // dp[i] = array ของความยาวที่ difference ต่าง ๆ
    // แต่ diff อาจเป็นลบได้ เรา shift โดย +500
    int** dp = (int**)malloc(numsSize * sizeof(int*));
    for (int i = 0; i < numsSize; i++) {
        dp[i] = (int*)calloc(1001, sizeof(int));
    }

    int maxLen = 0;

    for (int k = 1; k < numsSize; k++) {
        for (int j = 0; j < k; j++) {
            int diff = nums[k] - nums[j] + 500;
            dp[k][diff] = max(dp[k][diff], dp[j][diff] + 1);
            maxLen = max(dp[k][diff], maxLen);
        }
    }

    return maxLen + 1;
}