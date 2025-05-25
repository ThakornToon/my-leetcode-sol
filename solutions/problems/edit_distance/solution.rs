impl Solution {
    pub fn min_distance(word1: String, word2: String) -> i32 {
        let row = word1.len();
        let col = word2.len();
        if row == 0 || col == 0 {
            return row.max(col) as i32;
        }
        if word1 == word2 {
            return 0;
        }
        let mut prev: Vec<i32> = vec![0; col+1];
        let mut curr: Vec<i32> = vec![0; col+1];
        for j in 0..=col {
            prev[j] = j as i32;
        }
        for (mut i, ch1) in word1.chars().enumerate() {
            i+=1;
            curr[0] = i as i32;
            for (mut j, ch2) in word2.chars().enumerate() {
                j+=1;
                if ch1 == ch2 {
                    curr[j] = prev[j - 1];
                }
                else { 
                    curr[j] = prev[j - 1].min(curr[j - 1].min(prev[j])) + 1;
                }
            }

            for k in 0..=col {
                prev[k] = curr[k];
                curr[k] = 0;
            }
        }
        return prev[col];
    }
}