impl Solution {
    pub fn surface_area(grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        let mut area = 0;
        
        for i in 0..n {
            for j in 0..n {
                let height = grid[i][j];
                if height == 0 {
                    continue;
                }
                
                // พื้นที่ผิวทั้งหมด
                area += 6 * height;
                
                // ลบการซ้อนในแนวตั้ง
                area -= 2 * (height - 1);
                
                // ลบกับซ้าย
                if j > 0 {
                    area -= 2 * height.min(grid[i][j-1]);
                }
                
                // ลบกับบน
                if i > 0 {
                    area -= 2 * height.min(grid[i-1][j]);
                }
            }
        }
        
        area
    }
}