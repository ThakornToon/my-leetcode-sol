impl Solution {
    pub fn num_decodings(s: String) -> i32 {
        if s.starts_with('0') {
            return 0;
        }
        
        let n = s.len();
        const MOD: i64 = 1_000_000_007;
        let chars: Vec<char> = s.chars().collect();
        
        let mut prev_two: i64 = 1;
        let mut prev_one: i64 = 0;
        
        // Base case for first character
        prev_one = if chars[0] == '*' { 9 } else { 1 };
        
        for i in 1..n {
            let mut current_ways: i64 = 0;
            let current_char = chars[i];
            let prev_char = chars[i - 1];
            
            // Single digit decoding
            match current_char {
                '*' => current_ways = (prev_one * 9) % MOD,
                '0' => current_ways = 0,
                _ => current_ways = prev_one,
            }
            
            // Two digit decoding
            let ways_two_digits = match prev_char {
                '*' => match current_char {
                    '*' => 15,
                    '0'..='6' => 2,
                    _ => 1,
                },
                '1' => match current_char {
                    '*' => 9,
                    _ => 1,
                },
                '2' => match current_char {
                    '*' => 6,
                    '0'..='6' => 1,
                    _ => 0,
                },
                _ => 0,
            };
            
            current_ways = (current_ways + (prev_two * ways_two_digits) % MOD) % MOD;
            
            prev_two = prev_one;
            prev_one = current_ways;
        }
        
        prev_one as i32
    }
}