impl Solution {
    pub fn knight_probability(n: i32, k: i32, row: i32, column: i32) -> f64 {
        let n = n as usize;
        let k = k as usize;
        let row = row as usize;
        let column = column as usize;
        
        // Possible knight moves
        let moves: [(i32, i32); 8] = [
            (-2, -1), (-2, 1), (-1, -2), (-1, 2),
            (1, -2), (1, 2), (2, -1), (2, 1)
        ];
        
        // 3D DP array: dp[step][i][j]
        let mut dp = vec![vec![vec![0.0; n]; n]; k + 1];
        
        // Initial position at step 0
        dp[0][row][column] = 1.0;
        
        // For each step
        for step in 1..=k {
            for i in 0..n {
                for j in 0..n {
                    // If we can reach (i,j) at previous step
                    if dp[step-1][i][j] > 0.0 {
                        // Try all 8 moves
                        for &(dx, dy) in &moves {
                            let ni = i as i32 + dx;
                            let nj = j as i32 + dy;
                            
                            // Check if new position is on board
                            if ni >= 0 && ni < n as i32 && nj >= 0 && nj < n as i32 {
                                let ni = ni as usize;
                                let nj = nj as usize;
                                dp[step][ni][nj] += dp[step-1][i][j] / 8.0;
                            }
                        }
                    }
                }
            }
        }
        
        // Calculate total probability at step k
        let mut total_prob = 0.0;
        for i in 0..n {
            for j in 0..n {
                total_prob += dp[k][i][j];
            }
        }
        
        total_prob
    }
}