impl Solution {
    pub fn spiral_matrix_iii(rows: i32, cols: i32, r_start: i32, c_start: i32) -> Vec<Vec<i32>> {
        let rows = rows as usize;
        let cols = cols as usize;
        let mut r = r_start as i32;
        let mut c = c_start as i32;
        
        let dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]; // ขวา, ล่าง, ซ้าย, บน
        let mut dir = 0;
        let mut step = 1;
        
        let total = rows * cols;
        let mut result = Vec::with_capacity(total);
        
        // เพิ่มจุดเริ่มต้น
        result.push(vec![r, c]);
        
        while result.len() < total {
            // เดิน 2 ทิศทางด้วย step เดียวกัน
            for _ in 0..2 {
                // เดิน step ก้าว
                for _ in 0..step {
                    r += dirs[dir].0;
                    c += dirs[dir].1;
                    
                    // ตรวจสอบขอบเขต
                    if r >= 0 && (r as usize) < rows && c >= 0 && (c as usize) < cols {
                        result.push(vec![r, c]);
                        if result.len() == total {
                            return result;
                        }
                    }
                }
                // เปลี่ยนทิศทาง
                dir = (dir + 1) % 4;
            }
            // เพิ่ม step
            step += 1;
        }
        
        result
    }
}