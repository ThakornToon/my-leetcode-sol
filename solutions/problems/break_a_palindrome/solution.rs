impl Solution {
    pub fn break_palindrome(palindrome: String) -> String {
        let n = palindrome.len();
        
        // กรณีความยาว 1 ไม่สามารถเปลี่ยนได้
        if n == 1 {
            return String::new();
        }
        
        let mut chars: Vec<char> = palindrome.chars().collect();
        
        // หา char ที่ไม่ใช่ 'a' ตัวแรกในครึ่งแรก
        for i in 0..n / 2 {
            if chars[i] != 'a' {
                chars[i] = 'a';
                return chars.into_iter().collect();
            }
        }
        
        // ถ้าทุกตัวในครึ่งแรกเป็น 'a' ให้เปลี่ยนตัวสุดท้ายเป็น 'b'
        chars[n - 1] = 'b';
        chars.into_iter().collect()
    }
}