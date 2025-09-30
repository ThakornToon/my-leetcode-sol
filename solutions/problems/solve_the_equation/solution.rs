impl Solution {
    pub fn solve_equation(equation: String) -> String {
        let mut first_const = 0;
        let mut sec_const = 0;
        let mut first_x = 0;
        let mut sec_x = 0;

        let mut sign = 1;
        let mut left = true;
        let chars: Vec<char> = equation.chars().collect();
        let n = chars.len();
        let mut i = 0;
        
        while i < n {
            let mut num = 0;
            let mut has_num = false;
            
            while i < n && chars[i].is_ascii_digit() {
                num = num * 10 + (chars[i] as i32 - '0' as i32);
                i += 1;
                has_num = true;
            }

            if i < n && chars[i] == 'x' {
                if !has_num {
                    num = 1;
                }

                if left {
                    first_x += num * sign;
                } else {
                    sec_x += num * sign;
                }
                i += 1;
                
                if i < n && chars[i] == '-' {
                    sign = -1;
                    i += 1;
                } else if i < n {
                    sign = 1;
                    if chars[i] == '=' {
                        left = false;
                    }
                    i += 1;
                }
            } else if i < n && chars[i] == '-' {
                if left {
                    first_const += num * sign;
                } else {
                    sec_const += num * sign;
                }
                sign = -1;
                i += 1;
            } else if i < n {
                if left {
                    first_const += num * sign;
                } else {
                    sec_const += num * sign;
                }

                if chars[i] == '=' {
                    left = false;
                }
                sign = 1;
                i += 1;
            } else {
                sec_const += num * sign;
            }
        }

        first_x -= sec_x;
        sec_const -= first_const;
        
        if first_x == 0 && sec_const == 0 {
            return "Infinite solutions".to_string();
        } else if first_x == 0 {
            return "No solution".to_string();
        } else {
            let result = sec_const / first_x;
            return format!("x={}", result);
        }
    }
}