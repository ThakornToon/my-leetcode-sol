impl Solution {
    pub fn maximum_amount(coins: Vec<Vec<i32>>) -> i32 {
        let n = coins.len();
        let m = coins[0].len();
        let neg = -1_000_000_000;  // NEG = -1e9
        
        // dp[i][j][t] = max money from (i,j) to (n-1,m-1) with t neutralizations left
        let mut dp = vec![vec![vec![neg; 3]; m]; n];
        
        // Base case: ที่จุดหมาย (n-1, m-1)
        for t in 0..=2 {
            if coins[n-1][m-1] < 0 && t > 0 {
                dp[n-1][m-1][t] = 0;  // ใช้ neutralize
            } else {
                dp[n-1][m-1][t] = coins[n-1][m-1];
            }
        }
        
        // วนจากล่างขวาไปบนซ้าย
        for i in (0..n).rev() {
            for j in (0..m).rev() {
                if i == n-1 && j == m-1 {
                    continue;
                }
                
                for t in 0..=2 {
                    let mut ans = neg;
                    
                    // ค่าที่ดีที่สุดจากข้างล่างหรือข้างขวา
                    let mut nxt = neg;
                    if i + 1 < n {
                        nxt = nxt.max(dp[i+1][j][t]);
                    }
                    if j + 1 < m {
                        nxt = nxt.max(dp[i][j+1][t]);
                    }
                    
                    if nxt != neg {
                        // กรณี 1: ไม่ neutralize ที่ (i,j)
                        ans = ans.max(coins[i][j] + nxt);
                        
                        // กรณี 2: neutralize ที่ (i,j) (ถ้าเป็นลบและยัง neutralize ได้)
                        if coins[i][j] < 0 && t > 0 {
                            let mut nxt_neu = neg;
                            if i + 1 < n {
                                nxt_neu = nxt_neu.max(dp[i+1][j][t-1]);
                            }
                            if j + 1 < m {
                                nxt_neu = nxt_neu.max(dp[i][j+1][t-1]);
                            }
                            ans = ans.max(nxt_neu);
                        }
                    }
                    
                    dp[i][j][t] = ans;
                }
            }
        }
        
        dp[0][0][2]
    }
}