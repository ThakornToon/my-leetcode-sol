use std::collections::VecDeque;
impl Solution {
    pub fn predict_party_victory(senate: String) -> String {
        let n = senate.len();
        let mut radiant = VecDeque::new();
        let mut dire = VecDeque::new();
        
        // เก็บ index ของสมาชิกแต่ละพรรค
        for (i, c) in senate.chars().enumerate() {
            if c == 'R' {
                radiant.push_back(i);
            } else {
                dire.push_back(i);
            }
        }
        
        // จำลองกระบวนการโหวต
        while !radiant.is_empty() && !dire.is_empty() {
            let r_index = radiant.pop_front().unwrap();
            let d_index = dire.pop_front().unwrap();
            
            if r_index < d_index {
                // R โหวตก่อน และห้าม D
                radiant.push_back(r_index + n);
            } else {
                // D โหวตก่อน และห้าม R
                dire.push_back(d_index + n);
            }
        }
        
        if radiant.is_empty() {
            "Dire".to_string()
        } else {
            "Radiant".to_string()
        }
    }
}