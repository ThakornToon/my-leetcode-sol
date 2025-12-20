use std::collections::{HashSet, VecDeque};

impl Solution {
    pub fn is_escape_possible(blocked: Vec<Vec<i32>>, source: Vec<i32>, target: Vec<i32>) -> bool {
        if blocked.is_empty() {
            return true;
        }
        
        let blocked_set: HashSet<(i32, i32)> = blocked
            .iter()
            .map(|b| (b[0], b[1]))
            .collect();
        
        Self::bfs(&source, &target, &blocked_set) && 
        Self::bfs(&target, &source, &blocked_set)
    }
    
    fn bfs(start: &Vec<i32>, end: &Vec<i32>, blocked_set: &HashSet<(i32, i32)>) -> bool {
        let MAX_VISIT: usize = blocked_set.len() * blocked_set.len() / 2;
        const BOUNDARY: i32 = 1_000_000;
        
        let mut visited = HashSet::new();
        let mut queue = VecDeque::new();
        
        let start_point = (start[0], start[1]);
        queue.push_back(start_point);
        visited.insert(start_point);
        
        let directions = [(0, 1), (0, -1), (1, 0), (-1, 0)];
        
        while let Some((x, y)) = queue.pop_front() {
            // If we've visited enough cells
            if visited.len() > MAX_VISIT {
                return true;
            }
            
            // If reached target
            if x == end[0] && y == end[1] {
                return true;
            }
            
            for (dx, dy) in &directions {
                let nx = x + dx;
                let ny = y + dy;
                
                // Check bounds
                if nx < 0 || nx >= BOUNDARY || ny < 0 || ny >= BOUNDARY {
                    continue;
                }
                
                let new_point = (nx, ny);
                
                // Check if blocked or visited
                if blocked_set.contains(&new_point) || visited.contains(&new_point) {
                    continue;
                }
                
                visited.insert(new_point);
                queue.push_back(new_point);
            }
        }
        
        false
    }
}
