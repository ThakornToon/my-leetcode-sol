class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX;
        int profit = 0;
        for (int& sell : prices) {
            if (sell < buy) {
                buy = sell;
            }
            else {
                profit = max(profit, sell - buy);
            }
        }
        return profit;
    }
};