use std::collections::VecDeque;

impl Solution {
    pub fn shortest_bridge(grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        let mut visited = vec![vec![false; n]; n];
        let mut q = VecDeque::new();
        
        // ทิศทาง
        let dirs = [(-1,0), (0,1), (1,0), (0,-1)];
        
        // 1. หาเกาะแรก (DFS)
        'outer: for i in 0..n {
            for j in 0..n {
                if grid[i][j] == 1 {
                    // DFS สแต็ก
                    let mut stack = VecDeque::new();
                    stack.push_back((i, j));
                    visited[i][j] = true;
                    
                    while let Some((x, y)) = stack.pop_back() {
                        // เก็บพื้นที่เกาะเพื่อขยายภายหลัง
                        q.push_back((x, y));
                        
                        // ไปทุกทิศทาง
                        for (dx, dy) in dirs {
                            let nx = x as i32 + dx;
                            let ny = y as i32 + dy;
                            
                            if nx >= 0 && nx < n as i32 && ny >= 0 && ny < n as i32 {
                                let nx = nx as usize;
                                let ny = ny as usize;
                                
                                if !visited[nx][ny] && grid[nx][ny] == 1 {
                                    visited[nx][ny] = true;
                                    stack.push_back((nx, ny));
                                }
                            }
                        }
                    }
                    break 'outer; // เก็บทุกพื้นที่ในเกาะแรกครบ
                }
            }
        }
        
        // 2. BFS หาสะพาน(ขยายเกาะ)
        let mut steps = 0;
        while !q.is_empty() {
            let size = q.len();
            
            for _ in 0..size {
                let (x, y) = q.pop_front().unwrap();
                
                for (dx, dy) in dirs {
                    let nx = x as i32 + dx;
                    let ny = y as i32 + dy;
                    
                    if nx < 0 || nx >= n as i32 || ny < 0 || ny >= n as i32 {
                        continue;
                    }
                    
                    let nx = nx as usize;
                    let ny = ny as usize;
                    
                    if visited[nx][ny] {
                        continue;
                    }
                    
                    // เจอเกาะที่สอง
                    if grid[nx][ny] == 1 {
                        return steps;
                    }
                    
                    // เป็นน้ำ
                    visited[nx][ny] = true;
                    q.push_back((nx, ny));
                }
            }
            steps += 1;
        }
        
        -1
    }
}