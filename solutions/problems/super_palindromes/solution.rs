impl Solution {
    pub fn superpalindromes_in_range(left: String, right: String) -> i32 {
        let l: u64 = left.parse().unwrap();
        let r: u64 = right.parse().unwrap();
        let mut count = 0;
        
        // จำกัดที่ 100000 เพราะ p ≤ 10^9 
        for i in 1..100000 { // จะนำไปยกกำลังสองต่อ
            // สร้าง odd palindrome
            let s = i.to_string();
            let rev: String = s.chars().rev().collect();
            let odd_str = format!("{}{}", s, &rev[1..]);
            if let Ok(p_odd) = odd_str.parse::<u64>() {
                let x_odd: u64 = p_odd * p_odd;
                if x_odd > r {
                    break;
                }
                if x_odd >= l && Self::is_palindrome(x_odd) && Self::is_palindrome(p_odd) {
                    count += 1;
                }
            }
            
            // สร้าง even palindrome
            let even_str = format!("{}{}", s, rev);
            if let Ok(p_even) = even_str.parse::<u64>() {
                let x_even: u64 = p_even * p_even;
                if x_even >= l && x_even <= r && Self::is_palindrome(x_even) && Self::is_palindrome(p_even) {
                    count += 1;
                }
            }
        }
        
        count
    }

    fn is_palindrome(mut x: u64) -> bool {
        let original = x;
        let mut reverse = 0;
        while x > 0 {
            reverse = (reverse * 10) + (x % 10);
            x /= 10;
        }
        original == reverse
    }
}