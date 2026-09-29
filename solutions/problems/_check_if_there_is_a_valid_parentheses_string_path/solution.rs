impl Solution {
    pub fn has_valid_path(grid: Vec<Vec<char>>) -> bool {
        let m = grid.len();
        let n = grid[0].len();

        if (m + n - 1) % 2 != 0 || grid[0][0] == ')' || grid[m - 1][n - 1] == '(' {
            return false;
        }

        let max_bal = (m + n) / 2 + 1;
        // visited[r][c][bal]
        let mut visited = vec![vec![vec![false; max_bal]; n]; m];

        fn dfs(
            r: usize,
            c: usize,
            mut bal: i32,
            grid: &Vec<Vec<char>>,
            visited: &mut Vec<Vec<Vec<bool>>>,
            m: usize,
            n: usize,
        ) -> bool {
            bal += if grid[r][c] == '(' { 1 } else { -1 };

            let remaining_steps = ((m - 1 - r) + (n - 1 - c)) as i32;
            if bal < 0 || bal > remaining_steps {
                return false;
            }

            if r == m - 1 && c == n - 1 {
                return bal == 0;
            }

            let u_bal = bal as usize;
            if visited[r][c][u_bal] {
                return false;
            }
            visited[r][c][u_bal] = true;

            if r + 1 < m && dfs(r + 1, c, bal, grid, visited, m, n) {
                return true;
            }
            if c + 1 < n && dfs(r, c + 1, bal, grid, visited, m, n) {
                return true;
            }

            false
        }

        dfs(0, 0, 0, &grid, &mut visited, m, n)
    }
}