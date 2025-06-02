impl Solution {
    fn check(board: &Vec<String>, n: usize, row: usize, col: usize) -> bool {
        for i in 1..=row {
            if board[row - i].chars().nth(col - i) == Some('Q') {
                return false;
            }
            if board[row - i].chars().nth(col + i) == Some('Q') {
                return false;
            }
            if board[row - i].chars().nth(col) == Some('Q') {
                return false;
            }
        }
        return true;
    } 
    fn backtrack(res: &mut Vec<Vec<String>>, board: &mut Vec<String>, n: usize, row: usize) {
        if row == n {
            res.push(board.clone());
            return;
        }
        for i in 0..n {
            if Self::check(board, n, row, i) {
                if let Some(s) = board.get_mut(row) { //ASCII
                    s.replace_range(i..i+1, "Q");
                }
                Self::backtrack(res, board, n, row + 1);
                if let Some(s) = board.get_mut(row) { //ASCII
                    s.replace_range(i..i+1, ".");
                }
            }
        }
    }
    pub fn solve_n_queens(n: i32) -> Vec<Vec<String>> {
        let n: usize = n as usize;
        let mut res: Vec<Vec<String>> = Vec::new();
        let mut board: Vec<String> = vec![".".repeat(n); n];
        Self::backtrack(&mut res, &mut board, n, 0);
        return res;
    }
}