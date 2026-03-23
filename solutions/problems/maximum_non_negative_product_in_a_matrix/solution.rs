impl Solution {
    const MOD: i64 = 1_000_000_007;
    pub fn max_product_path(grid: Vec<Vec<i32>>) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        
        let mut dp_max = vec![i64::MIN; n];
        let mut dp_min = vec![i64::MAX; n];
        
        dp_max[0] = grid[0][0] as i64;
        dp_min[0] = grid[0][0] as i64;
        
        // เติมแถวแรก
        for j in 1..n {
            dp_max[j] = dp_max[j-1] * grid[0][j] as i64;
            dp_min[j] = dp_min[j-1] * grid[0][j] as i64;
        }
        
        for i in 1..m {
            // คำนวณ column 0 ก่อน
            let new_max = dp_max[0] * grid[i][0] as i64;
            let new_min = dp_min[0] * grid[i][0] as i64;
            dp_max[0] = new_max;
            dp_min[0] = new_min;
            
            for j in 1..n {
                let val = grid[i][j] as i64;
                
                let from_top_max = dp_max[j] * val;
                let from_top_min = dp_min[j] * val;
                let from_left_max = dp_max[j-1] * val;
                let from_left_min = dp_min[j-1] * val;
                
                let candidates = [from_top_max, from_top_min, from_left_max, from_left_min];
                
                dp_max[j] = *candidates.iter().max().unwrap();
                dp_min[j] = *candidates.iter().min().unwrap();
            }
        }
        
        let result = dp_max[n-1];
        if result < 0 {
            -1
        } else {
            (result % Self::MOD) as i32
        }
    }
}