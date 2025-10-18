impl Solution {
    pub fn soup_servings(n: i32) -> f64 {
        if n >= 4800 {
            return 1.0;
        }
        
        let servings = ((n + 24) / 25) as usize;
        let mut dp = vec![vec![-1.0; servings + 1]; servings + 1];
        
        Self::dfs(servings, servings, &mut dp)
    }
    
    fn dfs(a: usize, b: usize, dp: &mut Vec<Vec<f64>>) -> f64 {
        if a == 0 && b == 0 {
            return 0.5;
        }
        if a == 0 {
            return 1.0;
        }
        if b == 0 {
            return 0.0;
        }
        
        if dp[a][b] >= 0.0 {
            return dp[a][b];
        }
        
        let mut result = 0.0;
        result += Self::dfs(a.saturating_sub(4), b, dp);
        result += Self::dfs(a.saturating_sub(3), b.saturating_sub(1), dp);
        result += Self::dfs(a.saturating_sub(2), b.saturating_sub(2), dp);
        result += Self::dfs(a.saturating_sub(1), b.saturating_sub(3), dp);
        
        dp[a][b] = result * 0.25;
        dp[a][b]
    }
}