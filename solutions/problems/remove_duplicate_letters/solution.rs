impl Solution {
    pub fn remove_duplicate_letters(s: String) -> String {
        let mut count = [0; 26];
        let mut in_stack = [false; 26];
        let mut stack = Vec::new();
        
        // นับความถี่ของแต่ละตัวอักษร
        for c in s.chars() {
            count[(c as u8 - b'a') as usize] += 1;
        }
        
        for c in s.chars() {
            let idx = (c as u8 - b'a') as usize;
            count[idx] -= 1;  // ลดความถี่ของตัวอักษรปัจจุบัน
            
            if in_stack[idx] {
                continue;  // ข้ามถ้ามีใน Stack แล้ว
            }
            
            // นำตัวอักษรใน Stack ที่มากกว่าออกถ้ายังมีเหลือในสตริง
            while let Some(&top) = stack.last() {
                let top_idx = (top as u8 - b'a') as usize;
                if c < top && count[top_idx] > 0 {
                    in_stack[top_idx] = false;
                    stack.pop();
                } else {
                    break;
                }
            }
            
            stack.push(c);
            in_stack[idx] = true;
        }
        
        stack.into_iter().collect()
    }
}