impl Solution {
    pub fn di_string_match(s: String) -> Vec<i32> {
        let (mut low, mut high) = (0, s.len() as i32);
        
        let mut result: Vec<i32> = s
            .chars()
            .map(|c| {
                if c == 'I' {
                    let val = low;
                    low += 1;
                    val
                } else {
                    let val = high;
                    high -= 1;
                    val
                }
            })
            .collect();
        
        result.push(low); // low == high
        result
    }
}