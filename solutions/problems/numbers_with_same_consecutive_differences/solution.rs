impl Solution {
    pub fn nums_same_consec_diff(n: i32, k: i32) -> Vec<i32> {
        let mut result = Vec::new();
        
        // DFS function
        fn dfs(current: i32, length: i32, n: i32, k: i32, result: &mut Vec<i32>) {
            if length == n {
                result.push(current);
                return;
            }
            
            let last_digit = current % 10;
            
            // กรณี k = 0
            if k == 0 {
                dfs(current * 10 + last_digit, length + 1, n, k, result);
                return;
            }
            
            // ตัวเลือก 1: last_digit + k
            let next_digit = last_digit + k;
            if next_digit <= 9 {
                dfs(current * 10 + next_digit, length + 1, n, k, result);
            }
            
            // ตัวเลือก 2: last_digit - k
            let next_digit = last_digit - k;
            if next_digit >= 0 {
                dfs(current * 10 + next_digit, length + 1, n, k, result);
            }
        }
        
        // เริ่มจากหลักแรก (1-9)
        for first_digit in 1..=9 {
            dfs(first_digit, 1, n, k, &mut result);
        }
        
        result
    }
}