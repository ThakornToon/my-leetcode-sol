impl Solution {
    pub fn max_score_sightseeing_pair(values: Vec<i32>) -> i32 {
        let mut max_left = values[0] + 0;  // values[i] + i
        let mut max_score = i32::MIN;
        
        for j in 1..values.len() {
            // คำนวณ score สำหรับคู่ (i, j)
            let current_score = max_left + values[j] - j as i32;
            max_score = max_score.max(current_score);
            
            // อัปเดต max_left สำหรับ j ถัดไป
            max_left = max_left.max(values[j] + j as i32);
        }
        
        max_score
    }
}