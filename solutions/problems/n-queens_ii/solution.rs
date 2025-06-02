impl Solution {
    fn check(board: &Vec<Vec<char>>, n: usize, row: usize, col: usize) -> bool {
        for i in 1..=row {
            if (row as i32 - i as i32 >= 0) && (col as i32 - i as i32 >= 0) && board[row - i][col - i] == 'Q' {
                return false;
            }
            if (row as i32 - i as i32 >= 0) && ((col as i32) + (i as i32) < (n as i32)) && board[row - i][col + i] == 'Q' {
                return false;
            }
            if (row as i32 - i as i32 >= 0) && board[row - i][col] == 'Q' {
                return false;
            }
        }
        return true;
    } 
    fn backtrack(board: &mut Vec<Vec<char>>, n: usize, row: usize, count: &mut i32) {
        if row == n {
            *count+=1;
            return;
        }
        for i in 0..n {
            if Self::check(board, n, row, i) {
                board[row][i] = 'Q';
                Self::backtrack(board, n, row + 1, count);
                board[row][i] = '.';
            }
        }
    }
    pub fn total_n_queens(n: i32) -> i32 {
        let n: usize = n as usize;
        let mut count: i32 = 0;
        let mut board: Vec<Vec<char>> = vec![vec!['.'; n]; n];
        Self::backtrack(&mut board, n, 0, &mut count);
        return count;
    }
}