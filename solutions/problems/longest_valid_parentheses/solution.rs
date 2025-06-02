impl Solution {
    pub fn longest_valid_parentheses(s: String) -> i32 {
        let mut stack : Vec<usize> = Vec::new();
        let mut max_length = 0;
        let mut start = 0;
        for (i,c) in s.chars().enumerate() {
            if c == '(' {
                stack.push(i);
            }
            else {
                if stack.is_empty() {
                    start = i + 1;
                }
                else {
                    stack.pop();
                    if stack.is_empty() {
                        max_length = max_length.max(i-start+1);
                    }
                    else {
                        max_length = max_length.max(i - stack.last().unwrap());
                    }
                }
            }
        }
        return max_length as i32
    }
}