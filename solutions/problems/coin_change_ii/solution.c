int change(int amount, int* coins, int coinsSize) {
    unsigned long long* dp = (unsigned long long*)calloc(amount + 1, sizeof(unsigned long long));
    dp[0] = 1;
    
    for (int j = 0; j < coinsSize; ++j) {
        int coin = coins[j];
        for (int i = coin; i <= amount; ++i) {
            dp[i] += dp[i - coin];
        }
    }
    
    int result = dp[amount];
    free(dp);
    return result;
}