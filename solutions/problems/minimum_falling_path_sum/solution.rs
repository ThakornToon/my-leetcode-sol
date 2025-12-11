impl Solution {
    pub fn min_falling_path_sum(matrix: Vec<Vec<i32>>) -> i32 {
        let mut matrix = matrix;
        let n = matrix.len();
        
        for i in 1..n {
            for j in 0..n {
                let mut best = matrix[i-1][j];
                
                if j > 0 {
                    best = best.min(matrix[i-1][j-1]);
                }
                if j < n-1 {
                    best = best.min(matrix[i-1][j+1]);
                }
                
                matrix[i][j] += best;
            }
        }
        
        *matrix[n-1].iter().min().unwrap()
    }
}