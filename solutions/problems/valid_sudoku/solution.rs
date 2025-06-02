impl Solution {
    pub fn is_valid_sudoku(board: Vec<Vec<char>>) -> bool {
        let mut rowFlag: Vec<Vec<bool>> = vec![vec![false; 9]; 9];
        let mut colFlag: Vec<Vec<bool>> = vec![vec![false; 9]; 9];
        let mut cellFlag: Vec<Vec<bool>> = vec![vec![false; 9]; 9]; 
        
        for i in 0..9 {
            for j in 0..9 {
                if (board[i][j] != '.') {
                    let c: usize = board[i][j] as usize - '1' as usize;
                    if (rowFlag[i][c] || colFlag[c][j] || cellFlag[3 * (i / 3) + j / 3][c]) { //เช็คว่าตัวนั้นมีซ้ำไหม
                        return false;
                    }
                    rowFlag[i][c] = true;
                    colFlag[c][j] = true;
                    cellFlag[3 * (i / 3) + j / 3][c] = true;
                }
            }
        }
        return true;
    }
}