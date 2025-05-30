int maxProfit(int* prices, int pricesSize) {
    int profit = 0;
    int buy = prices[0];
    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] <= buy) {
            buy = prices[i];
        }
        else {
            profit += prices[i] - buy;
            buy = prices[i];
        }
    }
    return profit;
}