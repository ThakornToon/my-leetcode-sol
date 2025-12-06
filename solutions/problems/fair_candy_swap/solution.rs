use std::collections::HashSet;
impl Solution {
    pub fn fair_candy_swap(alice_sizes: Vec<i32>, bob_sizes: Vec<i32>) -> Vec<i32> {
        // sumA - x + y = sumB - y + x
        // y = x - (sumA - sumB) / 2
        let sum_a: i32 = alice_sizes.iter().sum();
        let sum_b: i32 = bob_sizes.iter().sum();
        
        let diff = (sum_a - sum_b) / 2;
        
        // สร้าง HashSet สำหรับ Bob
        let bob_set: HashSet<i32> = bob_sizes.into_iter().collect();
        
        // หาคู่ที่ตรงกัน
        for &x in &alice_sizes {
            let y = x - diff;
            if bob_set.contains(&y) {
                return vec![x, y];
            }
        }
        
        vec![] // ไม่ควรเกิดขึ้น
    }
}