impl Solution {
    pub fn max_satisfaction(satisfaction: Vec<i32>) -> i32 {
        let mut satisfaction = satisfaction;
        // มากไปน้อย
        satisfaction.sort_by(|a, b| b.cmp(a));
        
        let mut suffix_sum = 0;
        let mut result = 0;
        
        for &val in &satisfaction {
            suffix_sum += val;
            if suffix_sum <= 0 {
                break;
            }
            result += suffix_sum;
        }
        
        result
    }
}