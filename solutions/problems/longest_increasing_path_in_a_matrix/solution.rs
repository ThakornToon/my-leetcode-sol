impl Solution {
    fn go(matrix: &Vec<Vec<i32>>, mem: &mut Vec<Vec<i32>>, r: usize, c: usize) -> i32 {
        if mem[r][c] != 0 {
            return mem[r][c];
        }
        
        let mut count = 1;
        let current = matrix[r][c];
        
        // ตรวจสอบทิศทางขึ้น
        if r > 0 && current < matrix[r-1][c] {
            count = count.max(1 + Self::go(matrix, mem, r-1, c));
        }
        
        // ตรวจสอบทิศทางลง
        if r < matrix.len() - 1 && current < matrix[r+1][c] {
            count = count.max(1 + Self::go(matrix, mem, r+1, c));
        }
        
        // ตรวจสอบทิศทางซ้าย
        if c > 0 && current < matrix[r][c-1] {
            count = count.max(1 + Self::go(matrix, mem, r, c-1));
        }
        
        // ตรวจสอบทิศทางขวา
        if c < matrix[0].len() - 1 && current < matrix[r][c+1] {
            count = count.max(1 + Self::go(matrix, mem, r, c+1));
        }
        
        mem[r][c] = count;
        return count;
    }

    pub fn longest_increasing_path(matrix: Vec<Vec<i32>>) -> i32 {
        if matrix.is_empty() || matrix[0].is_empty() {
            return 0;
        }
        
        let rows = matrix.len();
        let cols = matrix[0].len();
        let mut mem = vec![vec![0; cols]; rows];
        let mut max_count = 0;
        
        for i in 0..rows {
            for j in 0..cols {
                max_count = max_count.max(Self::go(&matrix, &mut mem, i, j));
            }
        }
        
        max_count
    }
}