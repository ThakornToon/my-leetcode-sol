impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut buy = i32::MAX;
        let mut profit = 0;
        for &sell in prices.iter() {
            if sell < buy {
                buy = sell;
            }
            else {
                profit = profit.max(sell - buy);
            }
        }
        return profit;
    }
}