impl Solution {
    pub fn min_steps(s: String, t: String) -> i32 {
        let mut count = [0; 26];
        
        s.chars().for_each(|c| count[(c as u8 - b'a') as usize] += 1);
        t.chars().for_each(|c| count[(c as u8 - b'a') as usize] -= 1);
        
        count.iter().fold(0, |acc, &x| acc + x.max(0))
    }
}