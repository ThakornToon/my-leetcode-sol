int min(int a, int b) {
    return (a <= b) ? a : b;
}

int coinChangeHelper(int* coins, int coinsSize, int amount, int* memo) {
    if (amount == 0) return 0;
    if (memo[amount] != -1) return memo[amount];
    
    int minCoins = INT_MAX;
    
    for (int i = 0; i < coinsSize; i++) {
        if (coins[i] <= amount) {
            int res = coinChangeHelper(coins, coinsSize, amount - coins[i], memo);
            if (res != INT_MAX) {
                minCoins = min(minCoins, res + 1);
            }
        }
    }
    memo[amount] = minCoins;
    return minCoins;
}

int coinChange(int* coins, int coinsSize, int amount) {
    int memo[amount + 1];
    for (int i = 0; i <= amount; i++) {
        memo[i] = -1;
    }
    memo[0] = 0;
    int result = coinChangeHelper(coins, coinsSize, amount, memo);
    return result == INT_MAX ? -1 : result;
}