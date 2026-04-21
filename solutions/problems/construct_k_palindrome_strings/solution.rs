impl Solution {
    pub fn can_construct(s: String, k: i32) -> bool {
        let n = s.len();
        let k = k as usize;
        
        // ถ้า k > n ไม่สามารถสร้างได้
        if k > n {
            return false;
        }
        
        let mut freq = [0; 26];
        for c in s.chars() {
            freq[(c as u8 - b'a') as usize] += 1;
        }
        
        // นับจำนวนตัวอักษรที่มีความถี่เป็นเลขคี่
        let odd_count = freq.iter().filter(|&&count| count % 2 == 1).count();
        
        // palindrome แต่ละอันสามารถมีตัวคี่ได้มากสุด 1 ตัว
        odd_count <= k
    }
}