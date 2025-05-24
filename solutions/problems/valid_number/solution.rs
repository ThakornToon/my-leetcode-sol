impl Solution {
    pub fn is_number(s: String) -> bool {
        let mut isdot = false;
        let mut nums = false;
        let mut ise = false;
        let mut e_idx = s.len();
        for (i, c) in s.chars().enumerate() {
            if c.is_digit(10) {
                nums = true;
            }
            else if c == '+' || c == '-' {
                if i > 0 && i-1 != e_idx {
                    return false;
                }
            }
            else if c == 'e' || c == 'E' {
                if ise || !nums {
                    return false;
                }
                ise = true;
                nums = false;
                e_idx = i;
            }
            else if c == '.' {
                if isdot || ise {
                    return false;
                }
                isdot = true;
            }
            else {
                return false;
            }
        }
        return nums;
    }
}