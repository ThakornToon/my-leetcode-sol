double largestSumOfAverages(int* nums, int numsSize, int k) {
    double* prefix = (double*)malloc((numsSize + 1) * sizeof(double));
    double* dp = (double*)malloc((numsSize + 1) * sizeof(double));
    double* new_dp = (double*)malloc((numsSize + 1) * sizeof(double));
    
    // Calculate prefix sums
    prefix[0] = 0.0;
    for (int i = 0; i < numsSize; i++) {
        prefix[i + 1] = prefix[i] + nums[i];
    }
    
    // Initialize DP
    for (int i = 0; i < numsSize; i++) {
        dp[i + 1] = prefix[i + 1] / (i + 1);
    }
    
    // For additional partitions
    for (int group = 2; group <= k; group++) {
        memset(new_dp, 0, (numsSize + 1) * sizeof(double));
        
        for (int i = group - 1; i <= numsSize; i++) {
            for (int j = group - 1; j <= i; j++) {
                double avg = (prefix[i] - prefix[j - 1]) / (i - j + 1);
                if (dp[j - 1] + avg > new_dp[i]) {
                    new_dp[i] = dp[j - 1] + avg;
                }
            }
        }
        
        memcpy(dp, new_dp, (numsSize + 1) * sizeof(double));
    }
    
    double result = dp[numsSize];
    free(prefix);
    free(dp);
    free(new_dp);
    
    return result;
}