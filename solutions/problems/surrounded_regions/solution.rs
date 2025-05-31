impl Solution {
    pub fn solve(board: &mut Vec<Vec<char>>) {
        let boardSize = board.len();
        let boardColSize = board[0].len();
        if (boardSize < 3 || boardColSize < 3) {
            return;
        }
        fn dfs(row: usize, col: usize, board: &mut Vec<Vec<char>>, boardSize: usize, boardColSize: usize) {
            board[row][col] = 'R';
            if row > 0 && board[row - 1][col] == 'O' {
                dfs(row - 1, col, board, boardSize, boardColSize);
            }
            if row < boardSize - 1 && board[row + 1][col] == 'O' {
                dfs(row + 1, col, board, boardSize, boardColSize);
            }
            if col > 0 && board[row][col - 1] == 'O' {
                dfs(row, col - 1, board, boardSize, boardColSize);
            }
            if col < boardColSize - 1 && board[row][col + 1] == 'O' {
                dfs(row, col + 1, board, boardSize, boardColSize);
            }
        }
        
        for row in 0..boardSize {
            if board[row][0] == 'O' {
                dfs(row, 0, board, boardSize, boardColSize);
            }
            if board[row][boardColSize - 1] == 'O' {
                dfs(row, boardColSize - 1, board, boardSize, boardColSize);
            }
        }
        for col in 1..boardColSize {
            if board[0][col] == 'O' {
                dfs(0, col, board, boardSize, boardColSize);
            }
            if board[boardSize - 1][col] == 'O' {
                dfs(boardSize - 1, col, board, boardSize, boardColSize);
            }
        }
        for row in 0..boardSize {
            for col in 0..boardColSize {
                if board[row][col] == 'O' {
                    board[row][col] = 'X';
                } else if board[row][col] == 'R' {
                    board[row][col] = 'O';
                }
            }
        }
    }
}