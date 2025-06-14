int max(int a, int b) {
    return (a >= b) ? a : b;
}

int maxProfit(int* prices, int pricesSize, int fee) {
    int buy = -prices[0];
    int prev_buy = 0;
    int sell = 0;
    for (int i = 1; i < pricesSize; i++) {
        prev_buy = buy;
        buy = max(prev_buy, sell - prices[i]);
        sell = max(sell, prev_buy + prices[i] - fee);
    }
    return sell;
}