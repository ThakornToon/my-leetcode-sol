impl Solution {
    pub fn max_profit(prices: Vec<i32>, strategy: Vec<i32>, k: i32) -> i64 {
        let n = prices.len();
        let k = k as usize;
        // prefix[i] ผลรวม prices i ตัวแรก
        // ผลรวม index i..=j : prefix[j + 1] - prefix[i]
        let mut prefix = vec![0i64; n + 1];;
        let mut base_profit = 0i64;
        for i in 0..n {
            prefix[i + 1] = prefix[i] + prices[i] as i64;
            base_profit += (strategy[i] * prices[i]) as i64;
        }

        let half_k = k / 2;
        let mut original_sum = 0i64; // แบบไม่ได้ทำอะไรเลย
        let mut modified_sum = 0i64; // แบบมีการปรับค่า
        let mut max_change = 0i64; 
        
        // สำหรับช่วง [start, start+k-1]:
        // change = (sum(prices[start+half_k .. start+k-1]) - sum(strategy[i]*prices[i] สำหรับ i ในช่วง))
        
        // สร้าง window แรก
        for i in 0..k {
            original_sum += (strategy[i] * prices[i]) as i64;
            if (i >= half_k) {
                modified_sum += prices[i] as i64;  // ครึ่งหลังเปลี่ยนเป็น sell (1 * price)
            }
            // ครึ่งแรกเปลี่ยนเป็น hold (0 * price) = 0 ไม่ต้องบวก
        }
        
        let mut current_change: i64 = modified_sum - original_sum;
        max_change = if current_change > 0 {current_change} else {0};
        
        // Sliding window ไปจนสุด
        for start in 1..=(n - k) {
            let end = start + k - 1;
            
            // ออกจาก window: index start-1
            original_sum -= (strategy[start - 1] * prices[start - 1]) as i64;
            // ถ้า element ที่ออกเป็นครึ่งแรกของ window เก่า
            // ใน modification มันจะเป็น hold (0) ไม่ต้องทำอะไร
            // ถ้า element ที่ออกเป็นครึ่งหลังของ window เก่า
            modified_sum -= prices[start + half_k - 1] as i64;
            
            // เข้ามาใน window: index end 
            original_sum += (strategy[end] * prices[end]) as i64;
            // ถ้า element ที่เข้ามาเป็นครึ่งแรกของ window ใหม่
            // ใน modification มันจะเป็น hold (0) ไม่ต้องบวก
            // ถ้า element ที่เข้ามาเป็นครึ่งหลังของ window ใหม่
            modified_sum += prices[end] as i64;
            
            current_change = modified_sum - original_sum;
            if (current_change > max_change) {
                max_change = current_change;
            }
        }
        
        return base_profit + max_change; // การปรับที่ทำให้ค่าเพิ่มมากที่สุด
    }
}