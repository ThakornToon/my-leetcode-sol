impl Solution {
    pub fn can_partition_grid(grid: Vec<Vec<i32>>) -> bool {
        let m = grid.len();
        let n = grid[0].len();
        
        let mut prefix = vec![vec![0i64; n + 1]; m + 1];
        
        for i in 1..=m {
            for j in 1..=n {
                prefix[i][j] = (grid[i-1][j-1] as i64) + prefix[i-1][j] + 
                               prefix[i][j-1] - prefix[i-1][j-1];
            }
        }
        
        let total = prefix[m][n];
        if total % 2 != 0 {
            return false;
        }
        let target = total / 2;
        
        // ตรวจสอบแนวตั้ง
        for j in 1..n {
            if prefix[m][j] == target {
                return true;
            }
        }
        
        // ตรวจสอบแนวนอน
        for i in 1..m {
            if prefix[i][n] == target {
                return true;
            }
        }
        
        false
    }
}