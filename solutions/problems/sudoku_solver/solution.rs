impl Solution {
    pub fn solve_sudoku(board: &mut Vec<Vec<char>>) {
        fn valid(board: &mut Vec<Vec<char>>, r: usize, c: usize, dig: char) -> bool {
            for i in 0..9 {
                if board[r][i] == dig || board[i][c] == dig {
                    return false;
                }
            }
            
            let (r, c) = (r/3*3, c/3*3);
            for x in r..=r+2 {
                for y in c..=c+2 {
                    if board[x][y] == dig {
                        return false;
                    }
                }
            }

            return true;
        }

        fn solve(board: &mut Vec<Vec<char>>, r: usize, c: usize) -> bool {
            if r == 9 {
                return true;
            }

            let (mut x, mut y) = (r, c+1);
            if y == 9 {
                (x, y) = (r+1, 0);
            }

            if board[r][c] != '.' {
                return solve(board, x, y);
            }

            for dig in ['1','2','3','4','5','6','7','8','9'] {
                if valid(board, r, c, dig) {
                    board[r][c] = dig;
                    if solve(board, x, y) {
                        return true;
                    }
                    board[r][c] = '.';
                }
            }
            return false;
        }

        solve(board, 0, 0);       
    }
}