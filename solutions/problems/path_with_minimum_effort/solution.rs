use std::collections::VecDeque;

impl Solution {
    // effort = mid ไปถึงจุดหมายหรือไม่
    fn can_reach(heights: &Vec<Vec<i32>>, mid: i32) -> bool {
        let m = heights.len();
        let n = heights[0].len();
        let mut visited = vec![vec![false; n]; m];
        let mut queue = VecDeque::new();
        
        let dx = [0, 1, 0, -1];
        let dy = [1, 0, -1, 0];
        
        queue.push_back((0, 0));
        visited[0][0] = true;
        
        while let Some((x, y)) = queue.pop_front() {
            // ถึงจุดหมาย
            if x == m - 1 && y == n - 1 {
                return true;
            }
            
            // ไปทั้งสี่ทิศ
            for i in 0..4 {
                let nx = x as i32 + dx[i];
                let ny = y as i32 + dy[i];

                // ตรวจสอบขอบเขต
                if nx >= 0 && nx < m as i32 && ny >= 0 && ny < n as i32 {
                    let nx = nx as usize;
                    let ny = ny as usize;

                    // เคยมารึยัง
                    if !visited[nx][ny] {
                        let diff = (heights[nx][ny] - heights[x][y]).abs();

                        // ด้วย effort ปัจจุบันไปได้ไหม 
                        if diff <= mid {
                            visited[nx][ny] = true;
                            queue.push_back((nx, ny));
                        }
                    }
                }
            }
        }
        
        false
    }

    pub fn minimum_effort_path(heights: Vec<Vec<i32>>) -> i32 {
        let m = heights.len();
        let n = heights[0].len();
        
        let mut left = 0;
        let mut right = 0;
        for i in 0..m {
            for j in 0..n {
                right = right.max(heights[i][j]);
            }
        }
        
        // Binary Search หา effort ตัวแรกที่ทำให้ไปถึง
        while left < right {
            let mid = left + (right - left) / 2;
            // mid ไปได้ ตัวที่มากกว่า mid ก็ไปได้
            if Self::can_reach(&heights, mid) { 
                right = mid;
            } else {  
                left = mid + 1;
            }
        }
        
        left
    }
}