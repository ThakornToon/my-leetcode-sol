impl Solution {
    pub fn largest1_bordered_square(grid: Vec<Vec<i32>>) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        
        // สร้าง prefix sum arrays
        let mut hor = vec![vec![0; n]; m];
        let mut ver = vec![vec![0; n]; m];
        
        // คำนวณ prefix sum
        for i in 0..m {
            for j in 0..n {
                if grid[i][j] == 1 {
                    hor[i][j] = if j == 0 { 1 } else { hor[i][j-1] + 1 };
                    ver[i][j] = if i == 0 { 1 } else { ver[i-1][j] + 1 };
                }
            }
        }
        
        let mut max_size = 0;
        
        // ตรวจสอบทุกจุดจากขวาล่างไปซ้ายบน
        for i in (0..m).rev() {
            for j in (0..n).rev() {
                if grid[i][j] == 0 {
                    continue;
                }
                
                // ขนาดที่เป็นไปได้
                let possible_size = hor[i][j].min(ver[i][j]);
                
                // ตรวจสอบจากขนาดใหญ่ไปเล็ก
                for size in (max_size + 1..=possible_size).rev() {
                    let top = i as i32 - size as i32 + 1;
                    let left = j as i32 - size as i32 + 1;
                    
                    if top >= 0 && left >= 0 {
                        let top = top as usize;
                        let left = left as usize;
                        
                        // ตรวจสอบด้านบนและด้านซ้าย
                        if hor[top][j] >= size && ver[i][left] >= size {
                            max_size = max_size.max(size);
                            break;
                        }
                    }
                }
            }
        }
        
        (max_size * max_size) as i32
    }
}