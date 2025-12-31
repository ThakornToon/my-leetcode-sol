impl Solution {
    pub fn rearrange_characters(s: String, target: String) -> i32 {
        let mut s_count = [0; 26];
        s.bytes().for_each(|c| s_count[(c - b'a') as usize] += 1);
        
        let mut t_count = [0; 26];
        target.bytes().for_each(|c| t_count[(c - b'a') as usize] += 1);
        
        (0..26)
            .filter(|&i| t_count[i] > 0)
            .map(|i| if s_count[i] == 0 { 0 } else { s_count[i] / t_count[i] })
            .min()
            .unwrap_or(0)

    }
}