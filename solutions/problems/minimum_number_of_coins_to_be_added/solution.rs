impl Solution {
    pub fn minimum_added_coins(coins: Vec<i32>, target: i32) -> i32 {
        let mut miss: i64 = 1;
        let mut i = 0;
        let mut count = 0;
        let target = target as i64;
        let mut coins = coins;
        coins.sort();
        while (miss <= target) {
            if (i < coins.len() && coins[i] as i64 <= miss) {
                miss += coins[i] as i64;
                i += 1;
            } else {
                miss *= 2;
                count += 1;
            }
        }
        return count;
    }
}