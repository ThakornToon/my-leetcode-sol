impl Solution {
    pub fn full_justify(words: Vec<String>, max_width: i32) -> Vec<String> {
        let mut ans: Vec<String> = Vec::new();
        let n: usize = words.len();
        let mut idx: usize = 0;
        while idx < n {
            let mut start: usize = idx;
            let mut curr_line: i32 = 0; //count all space and character
            let mut sum_of_ch: i32 = 0; //count only character
            let mut last_line: bool = false;
            while idx < n && curr_line + (words[idx].len() as i32) <= max_width {
                curr_line += (words[idx].len() as i32) + 1;
                sum_of_ch += words[idx].len() as i32;
                idx+=1;
                if idx == n {
                    last_line = true;
                }
            }
            let mut extra: i32;
            let mut space: i32;
            curr_line = (idx - start) as i32; //change this variable to store number of word instead
            if last_line || curr_line == 1 {
                extra = 0;
                space = max_width - sum_of_ch;
            }
            else {
                extra = (max_width - sum_of_ch) % (curr_line - 1);
                space = (max_width - sum_of_ch) / (curr_line - 1);
            }
            let mut line = String::from("");
            if last_line {
                for i in start..idx {
                    line.push_str(&words[i]);
                    if i == idx-1 {
                        break;
                    }
                    line.push(' ');
                    space-=1;
                }
                for _ in 0..space {
                    line.push(' ');
                } 
            }
            else {
                for i in start..idx {
                    line.push_str(&words[i]);
                    if i == idx-1 && curr_line != 1 {
                        break;
                    }
                    for _ in 0..space {
                        line.push(' ');
                    } 
                    if extra > 0 {
                        line.push(' ');
                        extra-=1;
                    }
                }
            }
            ans.push(line);
        }
        return ans;
    }
}