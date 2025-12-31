impl Solution {
    pub fn max_number_of_balloons(text: String) -> i32 {
        let mut freq = [0; 26];
        text.bytes().for_each(|c| freq[(c - b'a') as usize] += 1);
        
        // ใช้ iterator และ min
        *[
            freq[1],            // b
            freq[0],            // a
            freq[11] / 2,       // l
            freq[14] / 2,       // o
            freq[13],           // n
        ].iter().min().unwrap()
    }
}