use std::collections::VecDeque;

impl Solution {
    pub fn max_distance(grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        let mut grid = grid;
        let mut queue = VecDeque::new();
        
        // เพิ่มจุดที่เป็นที่ดินทั้งหมด
        for i in 0..n {
            for j in 0..n {
                if grid[i][j] == 1 {
                    queue.push_back((i, j));
                }
            }
        }
        
        // ตรวจสอบกรณีพิเศษ
        if queue.is_empty() || queue.len() == n * n {
            return -1;
        }
        
        let directions = [(-1, 0), (1, 0), (0, -1), (0, 1)];
        let mut max_distance = -1;
        
        // BFS
        while !queue.is_empty() {
            let level_size = queue.len();
            max_distance += 1;
            
            for _ in 0..level_size {
                let (x, y) = queue.pop_front().unwrap();
                
                for (dx, dy) in &directions {
                    let nx = x as i32 + dx;
                    let ny = y as i32 + dy;
                    
                    if nx >= 0 && nx < n as i32 && ny >= 0 && ny < n as i32 {
                        let nx = nx as usize;
                        let ny = ny as usize;
                        
                        if grid[nx][ny] == 0 {
                            grid[nx][ny] = 1;  // ทำเครื่องหมายว่าเยือนแล้ว
                            queue.push_back((nx, ny));
                        }
                    }
                }
            }
        }
        
        max_distance
    }
}