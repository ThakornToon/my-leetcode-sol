impl Solution {
    pub fn max_matrix_sum(matrix: Vec<Vec<i32>>) -> i64 {
        let n = matrix.len();
        let mut total_sum: i64 = 0;
        let mut min_abs = i32::MAX;
        let mut negative_count = 0;
        
        for i in 0..n {
            for j in 0..n {
                let val = matrix[i][j];
                let abs_val = val.abs() as i64;
                total_sum += abs_val;
                
                if val < 0 {
                    negative_count += 1;
                }
                
                min_abs = min_abs.min(val.abs());
            }
        }
        
        if negative_count % 2 == 0 {
            total_sum
        } else {
            total_sum - 2 * (min_abs as i64)
        }
    }
}