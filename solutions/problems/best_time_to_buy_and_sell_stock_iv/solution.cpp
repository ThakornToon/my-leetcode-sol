class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int pricesSize = prices.size();
        vector<int> buy(k, INT_MAX);
        vector<int> profit(k, 0); 
        
        for (int i = 0; i < pricesSize; i++) {
            for (int j = 0; j < k ;j++){
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
};