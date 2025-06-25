impl Solution {
    fn reverse(chars: &mut Vec<char>, mut left: usize, mut right: usize) {
        while left < right {
            chars.swap(left, right);
            left += 1;
            right -= 1;
        }
    }
    
    fn clean_spaces(chars: &mut Vec<char>) {
        let n = chars.len();
        let mut i = 0;
        let mut j = 0;
        
        while j < n {
            while j < n && chars[j] == ' ' { j += 1; } // ข้ามช่องว่าง
            while j < n && chars[j] != ' ' { // ย้ายคำ
                if i != j {
                    chars[i] = chars[j];
                }
                i += 1;
                j += 1;
            }
            while j < n && chars[j] == ' ' { j += 1; } // ข้ามช่องว่างต่อ
            if j < n { // เพิ่มช่องว่างระหว่างคำ
                chars[i] = ' ';
                i += 1;
            }
        }
        
        chars.truncate(i); // ปรับขนาดเวกเตอร์
    }

    pub fn reverse_words(s: String) -> String {
        let mut chars: Vec<char> = s.chars().collect();
        
        // 1. ลบช่องว่างส่วนเกิน
        Self::clean_spaces(&mut chars);
        
        let mut n = chars.len();
        if n == 0 {
            return String::new();
        }
        
        // 2. Reverse ทั้งสตริง
        Self::reverse(&mut chars, 0, n - 1);
        
        // 3. Reverse แต่ละคำ
        n = chars.len();
        let mut i = 0;
        let mut j = 0;
        
        while i < n {
            while j < n && chars[j] != ' ' { j += 1; }
            Self::reverse(&mut chars, i, j - 1);
            i = j + 1;
            j = i;
        }
        
        chars.into_iter().collect()
    }
}