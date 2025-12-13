impl Solution {
    pub fn bag_of_tokens_score(tokens: Vec<i32>, power: i32) -> i32 {
        if tokens.is_empty() {
            return 0;
        }
        let mut sorted_tokens = tokens;
        sorted_tokens.sort_unstable();
        
        let mut power = power;
        let mut score = 0;
        let mut max_score = 0;
        let mut left = 0;
        let mut right = sorted_tokens.len() - 1;
        
        while left <= right {
            // ถ้าสามารถเล่น face-up ได้
            if power >= sorted_tokens[left] {
                power -= sorted_tokens[left];
                score += 1;
                left += 1;
                max_score = max_score.max(score);
            }
            // ถ้าสามารถเล่น face-down ได้
            else if score > 0 && left < right {
                power += sorted_tokens[right];
                score -= 1;
                right -= 1;
            }
            // หยุดเล่น
            else {
                break;
            }
        }
        
        max_score
    }
}