class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int buy = prices[0];
        for (int& sell : prices) {
            if (sell <= buy) {
                buy = sell;
            }
            else {
                profit += sell - buy;
                buy = sell;
            }
        }
        return profit;
    }
};