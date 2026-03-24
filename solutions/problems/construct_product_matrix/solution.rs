const MOD: i64 = 12345;

impl Solution {
    pub fn construct_product_matrix(grid: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let m = grid.len();
        let n = grid[0].len();
        
        // สร้าง result matrix และ initialize ด้วย 1
        let mut result = vec![vec![1; n]; m];
        
        // Forward pass: product of all elements before current
        let mut prod: i64 = 1;
        for i in 0..m {
            for j in 0..n {
                result[i][j] = ((result[i][j] as i64 * prod) % MOD) as i32;
                prod = (prod * (grid[i][j] as i64 % MOD)) % MOD;
            }
        }
        
        // Backward pass: multiply by product of all elements after current
        prod = 1;
        for i in (0..m).rev() {
            for j in (0..n).rev() {
                result[i][j] = ((result[i][j] as i64 * prod) % MOD) as i32;
                prod = (prod * (grid[i][j] as i64 % MOD)) % MOD;
            }
        }
        
        result
    }
}