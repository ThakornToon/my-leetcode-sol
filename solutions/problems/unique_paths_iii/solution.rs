impl Solution {
    pub fn unique_paths_iii(grid: Vec<Vec<i32>>) -> i32 {
        let mut grid = grid;
        let (m, n) = (grid.len(), grid[0].len());
        
        let mut start_x = 0;
        let mut start_y = 0;
        let mut empty_count = 1; // รวมจุดเริ่มต้น
        
        // หาจุดเริ่มต้นและนับช่องที่ต้องเดินผ่าน
        for i in 0..m {
            for j in 0..n {
                match grid[i][j] {
                    1 => {
                        start_x = i;
                        start_y = j;
                    }
                    0 => empty_count += 1,
                    _ => {}
                }
            }
        }
        
        Self::dfs(&mut grid, start_x, start_y, empty_count)
    }
    
    fn dfs(grid: &mut Vec<Vec<i32>>, x: usize, y: usize, empty_count: i32) -> i32 {
        let (m, n) = (grid.len(), grid[0].len());
        
        // ตรวจสอบขอบเขตและอุปสรรค
        if x >= m || y >= n || grid[x][y] == -1 {
            return 0;
        }
        
        // ถ้าเจอจุดสิ้นสุด
        if grid[x][y] == 2 {
            return if empty_count == 0 { 1 } else { 0 };
        }
        
        // Mark as visited
        grid[x][y] = -1;
        
        let dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)];
        let mut paths = 0;
        
        for (dx, dy) in dirs.iter() {
            let nx = x as i32 + dx;
            let ny = y as i32 + dy;
            
            if nx >= 0 && ny >= 0 {
                paths += Self::dfs(grid, nx as usize, ny as usize, empty_count - 1);
            }
        }
        
        // Backtrack
        grid[x][y] = 0;
        
        paths
    }
}