int maxProfit(int k, int* prices, int pricesSize) {
    int* buy = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        buy[i] = INT_MAX;
    }
    int* profit = (int*)calloc(k, sizeof(int));

    for (int i = 0; i < pricesSize; i++) {
        for (int j = 0; j < k; j++) {
            if (j > 0 && buy[j] > prices[i] - profit[j - 1]) {
                buy[j] = prices[i] - profit[j - 1];
            } else if (j == 0) {
                if (buy[j] > prices[i]) {
                    buy[j] = prices[i];
                }
            }

            if (profit[j] < prices[i] - buy[j]) {
                profit[j] = prices[i] - buy[j];
            }
        }
    }
    return profit[k - 1];
}