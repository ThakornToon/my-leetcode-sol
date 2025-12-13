impl Solution {
    pub fn distinct_subseq_ii(s: String) -> i32 {
        const MOD: i64 = 1_000_000_007;
    
        // end[char] = จำนวน subsequence ที่ลงท้ายด้วยตัวอักษรนี้
        let mut end = vec![0i64; 26];
        
        // sum = ผลรวมของ subsequence ทั้งหมดที่ผ่านมา
        let mut sum = 1i64; // รวม subsequence ว่าง
        
        for ch in s.chars() {
            let idx = (ch as u8 - b'a') as usize;
            
            // จำนวน subsequence ใหม่ที่ลงท้ายด้วยตัวอักษรนี้
            let new_count = sum;
            
            // ลบ subsequence ที่ลงท้ายด้วยตัวอักษรเดียวกันก่อนหน้า
            sum = (sum + new_count - end[idx] + MOD) % MOD;
            
            // อัปเดตจำนวน subsequence ที่ลงท้ายด้วยตัวอักษรนี้
            end[idx] = new_count;
        }
        
        ((sum - 1 + MOD) % MOD) as i32
    }
}