impl Solution {
    pub fn max_profit(k: i32, prices: Vec<i32>) -> i32 {
        let pricesSize = prices.len();
        let k = k as usize;
        let mut buy = vec![i32::MAX; k];
        let mut profit =vec![0; k]; 
        
        for i in 0..pricesSize {
            for j in 0..k {
                if (j > 0 && buy[j] > prices[i] - profit[j - 1]) {
                    buy[j] = prices[i] - profit[j - 1];
                } else if (j == 0 && buy[j] > prices[i]) {
                    buy[j] = prices[i];
                }

                if (profit[j] < prices[i] - buy[j]) {
                    profit[j] = prices[i] - buy[j];
                }
            }
        }
        return profit[k - 1];
    }
}