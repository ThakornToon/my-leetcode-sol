impl Solution {
    pub fn largest_magic_square(grid: Vec<Vec<i32>>) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        let max_size = m.min(n);
        
        // สร้าง prefix sum arrays
        let mut row_prefix = vec![vec![0; n + 1]; m + 1];
        let mut col_prefix = vec![vec![0; n + 1]; m + 1];
        
        // คำนวณ prefix sums
        for i in 1..=m {
            for j in 1..=n {
                row_prefix[i][j] = row_prefix[i][j-1] + grid[i-1][j-1];
                col_prefix[i][j] = col_prefix[i-1][j] + grid[i-1][j-1];
            }
        }
        
        // ฟังก์ชันช่วยคำนวณผลรวมแถว
        let get_row_sum = |r: usize, c1: usize, c2: usize| -> i32 {
            row_prefix[r+1][c2+1] - row_prefix[r+1][c1]
        };
        
        // ฟังก์ชันช่วยคำนวณผลรวมคอลัมน์
        let get_col_sum = |c: usize, r1: usize, r2: usize| -> i32 {
            col_prefix[r2+1][c+1] - col_prefix[r1][c+1]
        };
        
        // ไล่หาจากใหญ่ไปเล็ก
        for k in (2..=max_size).rev() {
            for i in 0..=m - k {
                for j in 0..=n - k {
                    // ตรวจสอบสี่เหลี่ยมที่เริ่มที่ (i,j) ขนาด k
                    
                    // หาผลรวมแถวแรกเป็น reference
                    let target = get_row_sum(i, j, j + k - 1);
                    let mut valid = true;
                    
                    // ตรวจสอบแถวอื่นๆ
                    for r in i+1..i+k {
                        if get_row_sum(r, j, j + k - 1) != target {
                            valid = false;
                            break;
                        }
                    }
                    if !valid { continue; }
                    
                    // ตรวจสอบคอลัมน์
                    for c in j..j+k {
                        if get_col_sum(c, i, i + k - 1) != target {
                            valid = false;
                            break;
                        }
                    }
                    if !valid { continue; }
                    
                    // ตรวจสอบเส้นทแยงมุมหลัก
                    let mut diag_sum = 0;
                    for d in 0..k {
                        diag_sum += grid[i+d][j+d];
                    }
                    if diag_sum != target { continue; }
                    
                    // ตรวจสอบเส้นทแยงมุมรอง
                    let mut anti_diag_sum = 0;
                    for d in 0..k {
                        anti_diag_sum += grid[i+d][j+k-1-d];
                    }
                    if anti_diag_sum != target { continue; }
                    
                    // พบ magic square
                    return k as i32;
                }
            }
        }
        
        // ไม่พบ magic square ที่ใหญ่กว่า 1x1
        1
    }
}