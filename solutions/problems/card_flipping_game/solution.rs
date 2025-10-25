use std::collections::HashSet;
use std::cmp::min;

impl Solution {
    pub fn flipgame(fronts: Vec<i32>, backs: Vec<i32>) -> i32 {
        let mut bad = HashSet::new();
        let n = fronts.len();
        
        // เก็บเลขที่ปรากฏทั้งสองด้านของบัตรเดียวกัน
        for i in 0..n {
            if fronts[i] == backs[i] {
                bad.insert(fronts[i]);
            }
        }
        
        let mut answer = i32::MAX;
        
        // ดูทุกเลขใน fronts และ backs
        for i in 0..n {
            if !bad.contains(&fronts[i]) {
                answer = min(answer, fronts[i]);
            }
            if !bad.contains(&backs[i]) {
                answer = min(answer, backs[i]);
            }
        }
        
        if answer == i32::MAX { 0 } else { answer }
    }
}