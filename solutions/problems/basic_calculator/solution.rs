impl Solution {
    pub fn calculate(s: String) -> i32 {
        let mut st: Vec<i32> = Vec::new();
        let mut res = 0;
        let mut curr = 0;
        let mut sign = 1;
        for ch in s.chars() {
            match ch {
                _ if ch.is_digit(10) => {
                    curr = (curr * 10) + ch.to_digit(10).unwrap() as i32;
                },
                '+' => {
                    res += sign * curr;
                    curr = 0;
                    sign = 1;
                },
                '-' => {
                    res += sign * curr;
                    curr = 0;
                    sign = -1;
                },
                '(' => {
                    st.push(res);
                    st.push(sign);
                    res = 0;
                    sign = 1;
                },
                ')' => {
                    res += sign * curr;
                    curr = 0;
                    res *= st.pop().unwrap();
                    res += st.pop().unwrap(); 
                }
                _ => ()
            }
        }
        return res + sign * curr;
    }
}