int maxProfit(int* prices, int pricesSize) {
    int buy = INT_MAX;
    int profit = 0;
    for (int i = 0; i < pricesSize; i++) {
        if (prices[i] < buy) {
            buy = prices[i];
        }
        else {
            if (profit < prices[i] - buy) {
                profit = prices[i] - buy;
            }
        }
    }
    return profit;
}