impl Solution {
    pub fn count_servers(grid: Vec<Vec<i32>>) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        
        let mut row_count = vec![0; m];
        let mut col_count = vec![0; n];
        
        // นับเซิร์ฟเวอร์
        for i in 0..m {
            for j in 0..n {
                if grid[i][j] == 1 {
                    row_count[i] += 1;
                    col_count[j] += 1;
                }
            }
        }
        
        // นับเซิร์ฟเวอร์ที่สื่อสารได้
        let mut result = 0;
        for i in 0..m {
            for j in 0..n {
                if grid[i][j] == 1 && (row_count[i] > 1 || col_count[j] > 1) {
                    result += 1;
                }
            }
        }
        
        result
    }
}