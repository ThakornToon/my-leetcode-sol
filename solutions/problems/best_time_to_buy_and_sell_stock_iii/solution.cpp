class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pricesSize = prices.size();
        if (pricesSize <= 1) {
            return 0;
        }
        int buy1 = INT_MAX;  
        int buy2 = INT_MAX;  
        
        int profit1 = 0;       
        int sum_profit = 0;       
        
        for (int i = 0; i < pricesSize; i++) {
            if (buy1 > prices[i]) {
                buy1 = prices[i]; //จะลองซื้อก็ต่อเมื่อเจอราคาที่ถูกกว่า
            }
            if (profit1 < prices[i] - buy1) {
                profit1 = prices[i] - buy1; //ลองขายหากได้กำไรมากกว่าเดิม
            }
            if (buy2 > prices[i] - profit1) {
                buy2 = prices[i] - profit1; //กำไรจากครั้งแรกมาหักแล้วถ้าได้ราคาถูกกว่าเดิมจะลองซื้อ
            }
            if (sum_profit < prices[i] - buy2) {
                sum_profit = prices[i] - buy2; //ขายหากได้ผลรวมกำไรมากกว่าเดิม
            }
        }
        return sum_profit;
    }
};