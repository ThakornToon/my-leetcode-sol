impl Solution {
    pub fn stone_game_v(stone_value: Vec<i32>) -> i32 {
        let n = stone_value.len();
        // prefix[i] = ผลรวม i ตัวแรก        
        let mut prefix = vec![0; n + 1];
        for i in 0..n {
            prefix[i + 1] = prefix[i] + stone_value[i];
        }
        
        let mut memo = vec![vec![-1; n]; n];
        
        Self::dfs(&stone_value, &prefix, 0, n - 1, &mut memo)
    }
    
    // ช่วง i ถึง j ได้ max สุดเท่าไร
    fn dfs(stones: &Vec<i32>, prefix: &Vec<i32>, i: usize, j: usize, memo: &mut Vec<Vec<i32>>) -> i32 {
        if i == j { return 0; }  // แบ่งไม่ได้แล้ว
        if memo[i][j] != -1 { return memo[i][j]; }  // คิดมาแล้ว
        
        let mut result = 0;
        // ลองแบ่งที่ k
        for k in i..j {
            let sum_left = prefix[k + 1] - prefix[i];
            let sum_right = prefix[j + 1] - prefix[k + 1];
            
            if sum_left < sum_right {  // ฝั่งขวาโดนโยน
                result = result.max(sum_left + Self::dfs(stones, prefix, i, k, memo));
            } else if sum_left > sum_right {  // ฝั่งซ้ายโดนโยน
                result = result.max(sum_right + Self::dfs(stones, prefix, k + 1, j, memo));
            } else {  // สองข้างเท่ากัน
                let left_score = Self::dfs(stones, prefix, i, k, memo);
                let right_score = Self::dfs(stones, prefix, k + 1, j, memo);
                result = result.max(sum_left + left_score.max(right_score));
            }
        }
        
        memo[i][j] = result;
        result
    }
}