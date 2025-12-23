use std::collections::VecDeque;

impl Solution {
    pub fn shortest_path_binary_matrix(grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        
        // จุดเริ่มต้นหรือจุดปลายเป็นกำแพง
        if grid[0][0] == 1 || grid[n-1][n-1] == 1 {
            return -1;
        }
        
        // 8 ทิศทาง
        let directions = [
            (-1, -1), (-1, 0), (-1, 1),
            (0, -1),           (0, 1),
            (1, -1),  (1, 0),  (1, 1)
        ];
        
        // distance matrix
        let mut dist = vec![vec![-1; n]; n];
        let mut queue = VecDeque::new();
        
        queue.push_back((0, 0));
        dist[0][0] = 1;
        
        while let Some((r, c)) = queue.pop_front() {
            // ถ้าถึงจุดหมาย
            if r == n-1 && c == n-1 {
                return dist[r][c];
            }
            
            // ตรวจสอบ 8 ทิศทาง
            for (dr, dc) in directions.iter() {
                let nr = r as i32 + dr;
                let nc = c as i32 + dc;
                
                if nr >= 0 && nr < n as i32 && nc >= 0 && nc < n as i32 {
                    let nr = nr as usize;
                    let nc = nc as usize;
                    
                    if grid[nr][nc] == 0 && dist[nr][nc] == -1 {
                        dist[nr][nc] = dist[r][c] + 1;
                        queue.push_back((nr, nc));
                    }
                }
            }
        }
        
        -1
    }
}