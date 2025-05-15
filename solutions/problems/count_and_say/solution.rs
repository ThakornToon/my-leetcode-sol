impl Solution {
    pub fn count_and_say(n: i32) -> String {
        if n == 1 {
            return "1".to_string();
        }

        let mut res = "1".to_string();
        
        for _ in 1..n {
            let mut next_res = String::new();
            let mut chars_arr = res.chars();
            let mut prev_char = chars_arr.next().unwrap();
            let mut count = 1;
            for ch in chars_arr { //เริ่มที่ index 1
                if ch == prev_char {
                    count += 1;
                } else {
                    next_res.push_str(&count.to_string());
                    next_res.push(prev_char);
                    prev_char = ch;
                    count = 1;
                }
            }
            next_res.push_str(&count.to_string());
            next_res.push(prev_char);
            res = next_res;
        }
        res
    }
}