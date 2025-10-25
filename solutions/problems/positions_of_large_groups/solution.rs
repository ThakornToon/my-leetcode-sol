impl Solution {
    pub fn large_group_positions(s: String) -> Vec<Vec<i32>> {
        let mut result = Vec::new();
        let chars: Vec<char> = s.chars().collect();
        let n = chars.len();
        
        let mut start = 0;
        for i in 1..=n {
            if i == n || chars[i] != chars[start] {
                let length = i - start;
                if length >= 3 {
                    result.push(vec![start as i32, (i - 1) as i32]);
                }
                start = i;
            }
        }
        
        result
    }
}