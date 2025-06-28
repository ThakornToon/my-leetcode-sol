impl Solution {
    pub fn decode_string(s: String) -> String {
        let mut stack: Vec<(String, i32)> = Vec::new();
        let mut next_num = 0;
        let mut curr_str = String::new();
        
        for ch in s.chars() {
            match ch {
                '[' => {
                    stack.push((curr_str, next_num));
                    curr_str = String::new();
                    next_num = 0;
                },
                ']' => {
                    let (prev_str, curr_num) = stack.pop().unwrap();
                    let temp = curr_str.clone();
                    for _ in 1..curr_num {
                        curr_str.push_str(&temp);
                    }
                    curr_str = format!("{}{}", prev_str, curr_str);
                },
                _ if ch.is_digit(10) => {
                    next_num = next_num * 10 + ch.to_digit(10).unwrap() as i32;
                },
                _ => {
                    curr_str.push(ch);
                }
            }
        }
        
        curr_str
    }
}