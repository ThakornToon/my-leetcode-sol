impl Solution {
    pub fn reverse_submatrix(grid: Vec<Vec<i32>>, x: i32, y: i32, k: i32) -> Vec<Vec<i32>> {
        let m = grid.len();
        let n = grid[0].len();
        let x = x as usize;
        let y = y as usize;
        let k = k as usize;
        
        // ตรวจสอบขอบเขต
        if x + k > m || y + k > n {
            return grid;
        }
        
        let mut result = grid.clone();
        
        // Flip submatrix แนวตั้ง
        for row in 0..k / 2 {
            let top_row = x + row;
            let bottom_row = x + k - 1 - row;
            
            for col in 0..k {
                let actual_col = y + col;
                result[top_row][actual_col] = grid[bottom_row][actual_col];
                result[bottom_row][actual_col] = grid[top_row][actual_col];
            }
        }
        
        result
    }
}