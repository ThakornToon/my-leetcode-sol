impl Solution {
    pub fn min_distance(houses: Vec<i32>, k: i32) -> i32 {
        let mut houses = houses;
        let k = k as usize;
        houses.sort();
        let n = houses.len();
        
        // precompute cost
        let mut cost = vec![vec![0; n]; n];
        for i in 0..n {
            for j in i..n {
                let median = houses[(i + j) / 2];
                cost[i][j] = houses[i..=j].iter().map(|&h| (h - median).abs()).sum();
            }
        }
        
        // 1D DP
        let mut prev = vec![0; n];
        let mut dp = vec![0; n];
        
        // base case: 1 mailbox
        for i in 0..n {
            prev[i] = cost[0][i];
        }
        
        // for mail = 2 to k
        for mail in 2..=k {
            for i in mail - 1..n {
                dp[i] = i32::MAX;
                for j in mail - 2..i {
                    if prev[j] != i32::MAX {
                        dp[i] = dp[i].min(prev[j] + cost[j + 1][i]);
                    }
                }
            }
            std::mem::swap(&mut dp, &mut prev);
        }
        
        prev[n - 1]
    }
}