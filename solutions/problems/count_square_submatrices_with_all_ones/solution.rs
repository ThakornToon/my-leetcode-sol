impl Solution {
    pub fn count_squares(matrix: Vec<Vec<i32>>) -> i32 {
        let rows = matrix.len();
        let cols = matrix[0].len();
        
        // ใช้แค่ 2 vectors
        let mut prev = vec![0; cols];
        let mut curr = vec![0; cols];
        
        let mut total = 0;
        
        for i in 0..rows {
            for j in 0..cols {
                if matrix[i][j] == 1 {
                    if i == 0 || j == 0 {
                        curr[j] = 1;
                    } else {
                        let min_val = prev[j].min(curr[j-1]).min(prev[j-1]);
                        curr[j] = min_val + 1;
                    }
                    total += curr[j];
                } else {
                    curr[j] = 0;
                }
            }
            
            // สลับ vectors
            std::mem::swap(&mut prev, &mut curr);
        }
        
        total
    }
}