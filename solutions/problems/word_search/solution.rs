impl Solution {
    pub fn exist(board: Vec<Vec<char>>, word: String) -> bool {
        let word_len: usize = word.len();
        let boardSize: usize = board.len();
        let boardColSize: usize = board[0].len();
        if word_len > boardSize * boardColSize {
            return false;
        }  
        let mut c_frist: i32 = 0;
        let mut board = board;
        let mut word_chars: Vec<char> = word.chars().collect();
        for i in 0..boardSize {
            for j in 0..boardColSize {
                if board[i][j] == word_chars[0] {
                    c_frist+=1;
                }
                else if board[i][j] == word_chars[word_len-1] {
                    c_frist-=1;
                }
            }
        }
        if c_frist > 0 {
            word_chars = word.chars().rev().collect()
        }

        fn dfs(board: &mut Vec<Vec<char>>, boardSize: usize, boardColSize: usize, word_chars: &[char], i: usize, j: usize, n: usize) -> bool { 
            if n == word_chars.len() {
                return true;
            }
            if(i < 0 || i >= boardSize || j < 0 || j >= boardColSize || board[i][j] != word_chars[n] as char) {
                return false;
            }
            board[i][j] = '0';
            let neighbor: bool = dfs(board, boardSize, boardColSize, word_chars, i+1, j, n+1) || dfs(board, boardSize, boardColSize, word_chars, i-1, j, n+1) || dfs(board, boardSize, boardColSize, word_chars, i, j-1, n+1) || dfs(board, boardSize, boardColSize, word_chars, i, j+1, n+1);
            board[i][j] = word_chars[n] as char;
            return neighbor;
        };

        for i in 0..boardSize {
            for j in 0..boardColSize {
                if dfs(&mut board, boardSize, boardColSize, &word_chars, i, j, 0) {
                    return true;
                }
            }
        }
        return false;
    }
}