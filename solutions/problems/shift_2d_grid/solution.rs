impl Solution {
    pub fn shift_grid(grid: Vec<Vec<i32>>, k: i32) -> Vec<Vec<i32>> {
        let m = grid.len();
        let n = grid[0].len();
        let total = m * n;
        let k = (k as usize) % total;
        
        if k == 0 {
            return grid;
        }
        
        // สร้าง grid ผลลัพธ์
        let mut result = vec![vec![0; n]; m];
        
        for i in 0..m {
            for j in 0..n {
                // คำนวณตำแหน่งใหม่ใน 1 มิติ
                let old_index = i * n + j;
                let new_index = (old_index + k) % total;
                
                // แปลงกลับเป็น 2 มิติ
                let new_row = new_index / n;
                let new_col = new_index % n;
                
                result[new_row][new_col] = grid[i][j];
            }
        }
        
        result
    }
}