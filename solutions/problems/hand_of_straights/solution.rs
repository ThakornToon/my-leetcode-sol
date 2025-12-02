use std::collections::HashMap;

impl Solution {
    pub fn is_n_straight_hand(hand: Vec<i32>, group_size: i32) -> bool {
        let n = hand.len();
        let k = group_size as usize;
        
        if n % k != 0 {
            return false;
        }
        
        // นับความถี่และเรียงลำดับ
        let mut freq = HashMap::new();
        for &card in &hand {
            *freq.entry(card).or_insert(0) += 1;
        }
        
        let mut pairs: Vec<(i32, i32)> = freq.into_iter().collect();
        pairs.sort(); // sort ตามหน้าการ์ดน้อยไปมาก
        let length = pairs.len();
        for i in 0..pairs.len() { 
            let (start_card, count) = pairs[i];
            
            if count > 0 {
                // เริ่มสร้างกลุ่มจาก start_card
                for offset in 0..k {
                    let target_card = start_card + offset as i32;
                    
                    // หาใน pairs
                    if i + offset < length && pairs[i + offset].0 == target_card && pairs[i + offset].1 >= count {
                        pairs[i + offset].1 -= count;
                    } else {
                        return false;
                    }
                }
            }
        }
        
        true
    }
}