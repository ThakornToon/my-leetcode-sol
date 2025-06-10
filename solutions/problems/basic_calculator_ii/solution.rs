impl Solution {
    pub fn calculate(s: String) -> i32 {
        let n = s.len();
        let s = s.as_bytes();
        let (mut res, mut curr, mut prev) = (0, 0, 0);
        let mut sign = b'+';
        let mut i = 0;
        while (i < n) {
            if s[i] == b' ' {
                i += 1;
                continue;
            }
            if s[i].is_ascii_digit() {
                while i < n && s[i].is_ascii_digit() {
                    curr = (curr) * 10 + (s[i] - b'0') as i32;
                    i += 1;
                }
                if sign == b'+' {
                    res += curr;
                    prev = curr;
                }
                else if sign == b'-' {
                    res -= curr;
                    prev = -curr;
                }
                else if sign == b'*' {
                    res -= prev;
                    res += (prev * curr);
                    prev = (prev * curr);
                }
                else if sign == b'/' {
                    res -= prev;
                    res += (prev / curr);
                    prev = (prev / curr);
                }
                curr = 0;
            }

            if (i == n) {
                break;
            }
            if (s[i] == b'+' || s[i] == b'-' || s[i] == b'*' || s[i] == b'/') {
                sign = s[i];
                i += 1;
            }
        }
        return res;
    }
}