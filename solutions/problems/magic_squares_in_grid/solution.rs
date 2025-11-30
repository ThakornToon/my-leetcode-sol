impl Solution {
    pub fn num_magic_squares_inside(grid: Vec<Vec<i32>>) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        
        if m < 3 || n < 3 {
            return 0;
        }
        
        let mut count = 0;
        
        for i in 0..=m-3 {
            for j in 0..=n-3 {
                if Self::is_magic_square(&grid, i, j) {
                    count += 1;
                }
            }
        }
        
        count
    }
    
    fn is_magic_square(grid: &Vec<Vec<i32>>, r: usize, c: usize) -> bool {
        // Check center
        if grid[r+1][c+1] != 5 {
            return false;
        }
        
        // Check distinct numbers 1-9
        let mut seen = [false; 10];
        for i in r..r+3 {
            for j in c..c+3 {
                let num = grid[i][j] as usize;
                if num < 1 || num > 9 || seen[num] {
                    return false;
                }
                seen[num] = true;
            }
        }
        
        // Check rows
        for i in 0..3 {
            let sum: i32 = (0..3).map(|j| grid[r+i][c+j]).sum();
            if sum != 15 {
                return false;
            }
        }
        
        // Check columns
        for j in 0..3 {
            let sum: i32 = (0..3).map(|i| grid[r+i][c+j]).sum();
            if sum != 15 {
                return false;
            }
        }
        
        // Check diagonals
        if grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2] != 15 {
            return false;
        }
        if grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c] != 15 {
            return false;
        }
        
        true
    }
}