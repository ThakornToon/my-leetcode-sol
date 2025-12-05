impl Solution {
    pub fn min_eating_speed(piles: Vec<i32>, h: i32) -> i32 {
        let max_pile: i32 = *piles.iter().max().unwrap();
        
        let (mut low, mut high) = (1, max_pile);
        
        while low < high {
            let mid = low + (high - low) / 2;
            
            // คำนวณเวลาทั้งหมด
            let mut hours: i32 = 0;
            for &pile in &piles {
                // hours += (pile as i64 + mid - 1) / mid;
                // หรือใช้ ceil_div
                hours += (pile + mid - 1) / mid;
                
                // Optimization: early break
                if hours > h {
                    break;
                }
            }
            
            if hours <= h {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        
        low as i32
    }
}