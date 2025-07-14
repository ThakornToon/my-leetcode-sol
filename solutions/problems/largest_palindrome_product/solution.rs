impl Solution {
    fn has_n_digit_factors(num: i64, n: i32) -> bool {
        let upper = 10_i64.pow(n as u32) - 1;
        let lower = 10_i64.pow((n - 1) as u32);
        
        for i in (lower..=upper).rev() {
            if i * i < num {
                break;
            }
            if num % i == 0 {
                let other = num / i;
                if other >= lower && other <= upper {
                    return true;
                }
            }
        }
        false
    }

    pub fn largest_palindrome(n: i32) -> i32 {
        let upper = 10_i64.pow(n as u32) - 1;
        let lower = 10_i64.pow((n - 1) as u32);
        
        for i in (lower..=upper).rev() {
            let s = i.to_string();
            let rev_s: String = s.chars().rev().collect();
            let palindrome_str = format!("{}{}", s, rev_s);
            let palindrome: i64 = palindrome_str.parse().unwrap();
            
            if Self::has_n_digit_factors(palindrome, n) {
                return (palindrome % 1337) as i32;
            }
        }
        
        9
    }
}