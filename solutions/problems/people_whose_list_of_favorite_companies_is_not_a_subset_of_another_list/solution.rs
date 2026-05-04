use std::collections::HashMap;

impl Solution {
    pub fn people_indexes(favorite_companies: Vec<Vec<String>>) -> Vec<i32> {
        let n = favorite_companies.len();
        
        // แมพชื่อบริษัทกับ index
        let mut company_to_idx = HashMap::new();
        let mut idx = 0;
        for list in &favorite_companies {
            for comp in list {
                if !company_to_idx.contains_key(comp) {
                    company_to_idx.insert(comp, idx);
                    idx += 1;
                }
            }
        }
        
        // แปลงแต่ละ person เป็น Vec<bool>
        let mut masks = vec![vec![false; idx]; n];
        for (i, list) in favorite_companies.iter().enumerate() {
            for comp in list {
                masks[i][company_to_idx[comp]] = true;
            }
        }
        
        let mut result = Vec::new();
        for i in 0..n {
            let mut is_subset = false;
            for j in 0..n {
                if i == j { continue; }
                
                // ตรวจสอบว่า masks[i] ⊆ masks[j]
                let mut all_found = true;
                for k in 0..idx {
                    if masks[i][k] && !masks[j][k] {
                        all_found = false;
                        break;
                    }
                }
                if all_found {
                    is_subset = true;
                    break;
                }
            }
            if !is_subset {
                result.push(i as i32);
            }
        }
        
        result
    }
}