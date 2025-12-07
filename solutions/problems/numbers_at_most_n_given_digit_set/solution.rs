impl Solution {
    pub fn at_most_n_given_digit_set(digits: Vec<String>, n: i32) -> i32 {
        let digits: Vec<char> = digits.into_iter().map(|s| s.chars().next().unwrap()).collect();
        let n_chars: Vec<char> = n.to_string().chars().collect();
        let k = n_chars.len();
        
        let mut dp = vec![0; k + 1]; // dp[i] = จำนวนตัวเลขที่มี i หลักแรกเหมือนกับ n และ ≤ n
        dp[k] = 1; // base case: ตัวเลขที่เท่ากับ n (ถ้าสร้างได้)
        
        // วนจากขวาไปซ้าย
        for (i, ch) in n_chars.into_iter().enumerate().rev() {
            let current_digit = ch.to_digit(10).unwrap() as u8;
            
            for d in &digits {
                let digit_val = *d as u8 - b'0';
                
                // กรณีที่หลักปัจจุบันสร้างจากตัวที่น้อยกว่า/เท่ากันกับหลักปัจจุบันใน n
                if digit_val < current_digit { 
                    dp[i] += (digits.len() as i32).pow((k - i - 1) as u32);
                } else if digit_val == current_digit {
                    dp[i] += dp[i + 1];
                }
            }
        }
        
        // บวกกรณีหลักน้อยกว่า k
        let mut result = dp[0];
        for i in 1..k {
            result += (digits.len() as i32).pow(i as u32);
        }
        
        result
    }
}