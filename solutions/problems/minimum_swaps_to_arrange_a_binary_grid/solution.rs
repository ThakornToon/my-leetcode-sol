impl Solution {
    pub fn min_swaps(grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        let mut trailing_zeros = vec![0; n];
        
        // คำนวณ trailing zeros ของแต่ละแถว
        for i in 0..n {
            let mut zeros = 0;
            // นับจากขวาไปซ้าย
            for j in (0..n).rev() {
                if grid[i][j] == 0 {
                    zeros += 1;
                } else {
                    break;
                }
            }
            trailing_zeros[i] = zeros;
        }
        
        let mut swaps = 0;
        
        // จัดเรียงแถว
        for i in 0..n {
            let required = (n - i - 1) as i32;  // จำนวน trailing zeros ที่ต้องการ
            let mut found = None;
            
            // หาแถวที่เหมาะสมจากตำแหน่ง i ลงไป
            for j in i..n {
                if trailing_zeros[j] >= required {
                    found = Some(j);
                    break;
                }
            }
            
            // ถ้าไม่พบ แสดงว่าเป็นไปไม่ได้
            match found {
                Some(pos) => {
                    // สลับแถว pos ขึ้นมาที่ i (bubble up)
                    for j in (i+1..=pos).rev() {
                        trailing_zeros.swap(j, j - 1);
                        swaps += 1;
                    }
                }
                None => return -1,
            }
        }
        
        swaps
    }
}