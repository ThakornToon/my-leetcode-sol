impl Solution {
    pub fn regions_by_slashes(grid: Vec<String>) -> i32 {
        let n = grid.len();
        let size = 3 * n;
        
        // สร้าง expanded grid
        let mut expanded = vec![vec![0; size]; size];
        
        // แปลงแต่ละ cell เป็น 3×3 block
        for (i, row) in grid.iter().enumerate() {
            for (j, ch) in row.chars().enumerate() {
                let base_x = 3 * i;
                let base_y = 3 * j;
                
                match ch {
                    '/' => {
                        expanded[base_x][base_y + 2] = 1;
                        expanded[base_x + 1][base_y + 1] = 1;
                        expanded[base_x + 2][base_y] = 1;
                    }
                    '\\' => {
                        expanded[base_x][base_y] = 1;
                        expanded[base_x + 1][base_y + 1] = 1;
                        expanded[base_x + 2][base_y + 2] = 1;
                    }
                    _ => {} // space ไม่ทำอะไร
                }
            }
        }
        
        // DFS เพื่อนับ regions
        let mut regions = 0;
        let mut stack = Vec::new();
        
        for i in 0..size {
            for j in 0..size {
                if expanded[i][j] == 0 {
                    regions += 1;
                    stack.push((i, j));
                    expanded[i][j] = 1;
                    
                    while let Some((x, y)) = stack.pop() {
                        // ตรวจสอบ 4 ทิศ
                        if x > 0 && expanded[x - 1][y] == 0 {
                            expanded[x - 1][y] = 1;
                            stack.push((x - 1, y));
                        }
                        if x + 1 < size && expanded[x + 1][y] == 0 {
                            expanded[x + 1][y] = 1;
                            stack.push((x + 1, y));
                        }
                        if y > 0 && expanded[x][y - 1] == 0 {
                            expanded[x][y - 1] = 1;
                            stack.push((x, y - 1));
                        }
                        if y + 1 < size && expanded[x][y + 1] == 0 {
                            expanded[x][y + 1] = 1;
                            stack.push((x, y + 1));
                        }
                    }
                }
            }
        }
        
        regions
    }
}