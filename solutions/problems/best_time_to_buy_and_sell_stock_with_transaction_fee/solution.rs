impl Solution {
    pub fn max_profit(prices: Vec<i32>, fee: i32) -> i32 {
        let mut buy = -prices[0];
        let mut prev_buy = 0;
        let mut sell = 0;
        let mut prev_sell = 0;
        for i in 1..prices.len() {
            prev_buy = buy;
            prev_sell = sell;
            buy = prev_buy.max(prev_sell - prices[i]);
            sell = prev_sell.max(prev_buy + prices[i] - fee);
        }
        return sell;
    }
}