impl Solution {
    pub fn smallest_sufficient_team(req_skills: Vec<String>, people: Vec<Vec<String>>) -> Vec<i32> {
        let n = req_skills.len();
        let m = people.len();
        
        // สร้าง skill to index mapping
        let mut skill_to_idx = std::collections::HashMap::new();
        for (i, skill) in req_skills.iter().enumerate() {
            skill_to_idx.insert(skill, i);
        }
        
        // แปลงทักษะของแต่ละคนเป็น bitmask
        let mut people_masks = vec![0; m];
        for (i, person_skills) in people.iter().enumerate() {
            let mut mask = 0;
            // ทำ mask ว่ามี req_skill ไหนบ้าง
            for skill in person_skills {
                if let Some(&idx) = skill_to_idx.get(skill) {
                    mask |= 1 << idx;
                }
            }
            people_masks[i] = mask;
        }
        
        let target_mask = (1 << n) - 1; // 11..1
        let dp_size = 1 << n;
        
        // dp[mask] = (จำนวนคน, คนสุดท้ายที่เลือก, mask ก่อนหน้า)
        let mut dp = vec![(m + 1, 0, 0); dp_size];
        dp[0] = (0, 0, 0);
        
        for i in 0..m {
            let person_mask = people_masks[i];
            if person_mask == 0 {
                continue;
            }
            
            // คิดทุกกรณีจากบนลงล่างเพื่อหากรณีที่ดีที่สุดและไม่เลือกคนซ้ำ
            for mask in (0..dp_size).rev() {
                let new_mask = mask | person_mask;
                // dp[mask | peopleMask[i]] = min(dp[mask] + 1)
                if dp[mask].0 + 1 < dp[new_mask].0 {
                    dp[new_mask] = (dp[mask].0 + 1, i, mask);
                }
            }
        }
        
        // Backtrack คิดย้อนกลับเพื่อหาคนที่เลือก
        let mut result = Vec::new();
        let mut mask = target_mask;
        
        while mask > 0 {
            let (_, person_idx, prev_mask) = dp[mask];
            result.push(person_idx as i32);
            mask = prev_mask;
        }
        
        result
    }
}