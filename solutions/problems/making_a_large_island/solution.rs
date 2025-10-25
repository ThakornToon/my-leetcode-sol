use std::collections::{HashSet, VecDeque};

impl Solution {
    pub fn largest_island(grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        let mut island_id = vec![vec![-1; n]; n];
        let mut island_sizes = Vec::new();
        let directions = [(0, 1), (1, 0), (0, -1), (-1, 0)];
        
        // Assign IDs and calculate sizes using BFS
        for i in 0..n {
            for j in 0..n {
                if grid[i][j] == 1 && island_id[i][j] == -1 {
                    let mut size = 0;
                    let mut queue = VecDeque::new();
                    queue.push_back((i, j));
                    island_id[i][j] = island_sizes.len() as i32;
                    
                    while let Some((x, y)) = queue.pop_front() {
                        size += 1;
                        
                        for &(dx, dy) in &directions {
                            let nx = x as i32 + dx;
                            let ny = y as i32 + dy;
                            
                            if nx >= 0 && nx < n as i32 && ny >= 0 && ny < n as i32 {
                                let nx = nx as usize;
                                let ny = ny as usize;
                                
                                if grid[nx][ny] == 1 && island_id[nx][ny] == -1 {
                                    island_id[nx][ny] = island_sizes.len() as i32;
                                    queue.push_back((nx, ny));
                                }
                            }
                        }
                    }
                    island_sizes.push(size);
                }
            }
        }
        
        if island_sizes.is_empty() {
            return 1;
        }
        
        let mut max_area = *island_sizes.iter().max().unwrap();
        
        // Check each water cell
        for i in 0..n {
            for j in 0..n {
                if grid[i][j] == 0 {
                    let mut connected_islands = HashSet::new();
                    let mut area = 1;
                    
                    for &(dx, dy) in &directions {
                        let nx = i as i32 + dx;
                        let ny = j as i32 + dy;
                        
                        if nx >= 0 && nx < n as i32 && ny >= 0 && ny < n as i32 {
                            let nx = nx as usize;
                            let ny = ny as usize;
                            
                            if grid[nx][ny] == 1 {
                                let neighbor_id = island_id[nx][ny];
                                if connected_islands.insert(neighbor_id) {
                                    area += island_sizes[neighbor_id as usize];
                                }
                            }
                        }
                    }
                    max_area = max_area.max(area);
                }
            }
        }
        
        max_area
    }
}