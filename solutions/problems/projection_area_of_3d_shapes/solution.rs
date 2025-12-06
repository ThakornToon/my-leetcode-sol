impl Solution {
    pub fn projection_area(grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        let mut xy = 0;
        let mut xz = 0;
        let mut yz = 0;
        
        // ค่าสูงสุดของแต่ละ column
        let mut col_max = vec![0; n];
        
        for i in 0..n {
            let mut row_max = 0;
            
            for j in 0..n {
                // XY-plane
                if grid[i][j] > 0 {
                    xy += 1;
                }
                
                // หา max ใน row
                if grid[i][j] > row_max {
                    row_max = grid[i][j];
                }
                
                // หา max ใน column
                if grid[i][j] > col_max[j] {
                    col_max[j] = grid[i][j];
                }
            }
            
            yz += row_max;
        }
        
        // รวม column max
        for &max_val in &col_max {
            xz += max_val;
        }
        
        xy + xz + yz
    }
}