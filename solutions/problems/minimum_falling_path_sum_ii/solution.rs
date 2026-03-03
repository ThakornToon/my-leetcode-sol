impl Solution {
    pub fn min_falling_path_sum(grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        let mut dp = vec![vec![0; n]; n];
        
        // base case
        dp[0] = grid[0].clone();
        
        for i in 1..n {
            for j in 0..n {
                // หาค่าน้อยที่สุดจากแถวก่อนหน้า ที่ไม่ใช้คอลัมน์ j
                let min_prev = (0..n)
                    .filter(|&k| k != j)
                    .map(|k| dp[i-1][k])
                    .min()
                    .unwrap();
                
                dp[i][j] = grid[i][j] + min_prev;
            }
        }
        
        *dp[n-1].iter().min().unwrap()
    }
}