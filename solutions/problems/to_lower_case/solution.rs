impl Solution {
    pub fn to_lower_case(s: String) -> String {
        s.chars()
         .map(|c| {
             match c {
                 'A'..='Z' => ((c as u8) + 32) as char,
                 _ => c
             }
         })
         .collect()
    }
}