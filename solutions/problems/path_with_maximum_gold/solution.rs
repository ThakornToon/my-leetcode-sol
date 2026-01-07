impl Solution {
    pub fn get_maximum_gold(grid: Vec<Vec<i32>>) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        let mut max_gold = 0;
        let mut grid_clone = grid.clone();

        // สำรวจทุกเซลล์
        for i in 0..m {
            for j in 0..n {
                if grid[i][j] > 0 {
                    let gold = Self::dfs(&mut grid_clone, i as i32, j as i32);
                    max_gold = max_gold.max(gold);
                }
            }
        }
        
        max_gold
    }
    
    // ฟังก์ชัน DFS แบบ recursive
    fn dfs(grid: &mut Vec<Vec<i32>>, row: i32, col: i32) -> i32 {
        let m = grid.len() as i32;
        let n = grid[0].len() as i32;
        
        // ตรวจสอบขอบเขตและค่า
        if row < 0 || row >= m || col < 0 || col >= n || grid[row as usize][col as usize] == 0 {
            return 0;
        }
        
        // เก็บค่าปัจจุบัน
        let current_gold = grid[row as usize][col as usize];
        
        // ทำเครื่องหมายว่าเยี่ยมชมแล้ว
        grid[row as usize][col as usize] = 0;
        
        // สำรวจทุกทิศทาง
        let directions = [(0, 1), (1, 0), (0, -1), (-1, 0)];
        let mut max_from_here = 0;
        
        for &(dr, dc) in &directions {
            let new_row = row + dr;
            let new_col = col + dc;
            
            max_from_here = max_from_here.max(Self::dfs(grid, new_row, new_col));
        }
        
        // คืนค่ากลับ
        grid[row as usize][col as usize] = current_gold;
        
        current_gold + max_from_here
    }
}