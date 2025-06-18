impl Solution {
    pub fn can_construct(ransom_note: String, magazine: String) -> bool {
        let mut counter = vec![0i32; 26];
        for ch in magazine.as_bytes() {
            counter[(ch - b'a') as usize] += 1;
        }
        
        for ch in ransom_note.as_bytes() {
            if counter[(ch - b'a') as usize] == 0 {
                return false;
            }
            counter[(ch - b'a') as usize] -= 1;
        }
        
        true
    }
}