impl Solution {
    fn backtrack(num: &[char], idx: usize, target: i64, ans: &mut Vec<String>, curr: &mut String, val: i64, multed: i64) {
        if idx == num.len() {
            if val == target {
                ans.push(curr.clone());
            }
            return;
        }

        for i in idx..num.len() {
            if i != idx && num[idx] == '0' {
                break;
            }

            let num_str: String = num[idx..=i].iter().collect();
            let curr_num: i64 = num_str.parse().unwrap();
            let old_len = curr.len();
            if idx == 0 {
                curr.push_str(&num_str);
                Self::backtrack(num, i + 1, target, ans, curr, curr_num, curr_num);
                curr.truncate(old_len);
            } else {
                // การบวก
                curr.push('+');
                curr.push_str(&num_str);
                Self::backtrack(num, i + 1, target, ans, curr, val + curr_num, curr_num);
                curr.truncate(old_len);

                // การลบ
                curr.push('-');
                curr.push_str(&num_str);
                Self::backtrack(num, i + 1, target, ans, curr, val - curr_num, -curr_num);
                curr.truncate(old_len);

                // การคูณ
                if multed == 0 || curr_num <= i64::MAX / multed.abs() {
                    let new_multed = multed * curr_num;
                    curr.push('*');
                    curr.push_str(&num_str);
                    Self::backtrack(num, i + 1, target, ans, curr, val - multed + new_multed, new_multed);
                    curr.truncate(old_len);
                }
            }
        }
    }
    pub fn add_operators(num: String, target: i32) -> Vec<String> {
        let mut ans = Vec::new();
        let num_chars: Vec<char> = num.chars().collect();
        let mut curr = String::new();
        
        Self::backtrack(&num_chars, 0, target as i64, &mut ans, &mut curr, 0, 1);
        
        ans
    }
}