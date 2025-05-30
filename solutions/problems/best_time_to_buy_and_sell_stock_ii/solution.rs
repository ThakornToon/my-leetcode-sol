impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut profit = 0;
        let mut buy = prices[0];
        for &sell in prices.iter() {
            if sell <= buy {
                buy = sell;
            }
            else {
                profit += sell - buy;
                buy = sell;
            }
        }
        return profit;
    }
}