impl Solution {
    pub fn hit_bricks(grid: Vec<Vec<i32>>, hits: Vec<Vec<i32>>) -> Vec<i32> {
        let m = grid.len();
        let n = grid[0].len();
        let mut result = vec![0; hits.len()];
        
        // สำรอง grid เดิมไว้ตรวจสอบ
        let original = grid.clone();
        let mut work = grid.clone();
        
        // จำลองการตีอิฐทั้งหมดก่อน
        for hit in &hits {
            let i = hit[0] as usize;
            let j = hit[1] as usize;
            if work[i][j] == 1 {
                work[i][j] = 0;
            }
        }
        
        // Mark stable bricks (ที่ยังเชื่อมต่อกับด้านบน)
        let mut stable = vec![vec![false; n]; m];
        
        // Mark top row as stable
        for j in 0..n {
            if work[0][j] == 1 {
                Self::mark_stable(&mut work, &mut stable, 0, j);
            }
        }
        
        // Process hits in reverse
        for k in (0..hits.len()).rev() {
            let i = hits[k][0] as usize;
            let j = hits[k][1] as usize;
            
            if original[i][j] == 1 { // ถ้าตีโดนอิฐจริงๆ
                work[i][j] = 1; // เอาก้อนอิฐกลับมา
                
                // เช็คว่าก้อนนี้เชื่อมกับ stable หรือไม่
                let mut connected = false;
                if i == 0 {
                    connected = true; // อยู่แถวบนสุด
                }
                
                // เช็คเพื่อนบ้านว่ามี stable ไหม
                let dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)];
                for &(di, dj) in &dirs {
                    let ni = i as i32 + di;
                    let nj = j as i32 + dj;
                    if ni >= 0 && ni < m as i32 && nj >= 0 && nj < n as i32 {
                        let ni = ni as usize;
                        let nj = nj as usize;
                        if stable[ni][nj] {
                            connected = true;
                            break;
                        }
                    }
                }
                
                // ถ้าก้อนนี้ stable
                if connected {
                    // นับอิฐที่กลับมาเชื่อมต่อใหม่
                    let count = Self::mark_stable(&mut work, &mut stable, i, j) - 1; // ไม่นับก่อนที่ตี
                    result[k] = count;
                }
            }
        }
        
        result
    }

    // นับอิฐไม่ stable ที่จะกลายเป็น stable และ mark ไปด้วย(นับอิฐฟื้นฟู)
    fn mark_stable(grid: &mut Vec<Vec<i32>>, stable: &mut Vec<Vec<bool>>, i: usize, j: usize) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        
        // ดูว่าเงื่อนไขปัจจุบันจะทำให้เปลี่ยนเป็น stable ไหม (ถ้า stable อยู่แล้วเราจะไม่สนใจ)
        if i >= m || j >= n || grid[i][j] != 1 || stable[i][j] {
            return 0;
        }
        
        // ถ้าปัจจุบัน stable จะขยายไปรอบๆด้วย
        stable[i][j] = true;
        let mut count = 1;
        
        let dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)];
        for &(di, dj) in &dirs {
            let ni = i as i32 + di;
            let nj = j as i32 + dj;
            if ni >= 0 && ni < m as i32 && nj >= 0 && nj < n as i32 {
                count += Self::mark_stable(grid, stable, ni as usize, nj as usize);
            }
        }
        
        count
    }
}