impl Solution {
    pub fn max_students(seats: Vec<Vec<char>>) -> i32 {
        let m = seats.len();
        let n = seats[0].len();
        let max_mask = 1 << n;
        
        let mut broken = vec![0; m];
        for i in 0..m {
            let mut mask = 0;
            for j in 0..n {
                if seats[i][j] == '#' {
                    mask |= 1 << j;
                }
            }
            broken[i] = mask;
        }
        
        let mut memo = vec![vec![-1; max_mask]; m + 1];
        
        fn dfs(row: usize, prev_mask: usize, broken: &[usize], memo: &mut Vec<Vec<i32>>, n: usize) -> i32 {
            if row == broken.len() { return 0; }
            if memo[row][prev_mask] != -1 { return memo[row][prev_mask]; }
            
            let mut res = 0;
            for mask in 0..(1 << n) {
                if (mask & broken[row]) != 0 { continue; }
                if (mask & (mask << 1)) != 0 { continue; }
                if (prev_mask & (mask << 1)) != 0 { continue; }
                if (prev_mask & (mask >> 1)) != 0 { continue; }
                
                let cnt = mask.count_ones() as i32;
                res = res.max(cnt + dfs(row + 1, mask, broken, memo, n));
            }
            
            memo[row][prev_mask] = res;
            res
        }
        
        dfs(0, 0, &broken, &mut memo, n)
    }
}