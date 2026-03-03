impl Solution {
    pub fn palindrome_partition(s: String, k: i32) -> i32 {
        let s = s.as_bytes();
        let n = s.len();
        let k = k as usize;
        
        // cost[i][j] = จำนวนการเปลี่ยนเพื่อทำให้ s[i..j] เป็น palindrome
        // เริ่มต้นด้วย 0 ทั้งหมด
        let mut cost = vec![vec![0; n]; n];
        
        // คำนวณ cost สำหรับทุก substring
        // เริ่มจากความยาว 2 ขึ้นไป (ความยาว 1 ไม่ต้องเปลี่ยน)
        for length in 2..=n {
            for i in 0..=n - length {
                let j = i + length - 1;
                // ถ้าตัวแรกและตัวสุดท้ายต่างกัน ต้องเปลี่ยน 1 ตัว
                // บวกกับ cost ของ substring ข้างใน (i+1 ถึง j-1)
                cost[i][j] = cost[i + 1][j - 1] + if s[i] != s[j] { 1 } else { 0 };
            }
        }
        
        // dp[i][p] = min cost สำหรับ s[0..i] แบ่งเป็น p ส่วน
        // ใช้ i32::MAX สำหรับค่าที่ยังไม่สามารถทำได้
        let mut dp = vec![vec![i32::MAX; k + 1]; n];
        
        // Base case: แบ่งเป็น 1 ส่วน = cost[0][i]
        for i in 0..n {
            dp[i][1] = cost[0][i];
        }
        
        // คำนวณ DP สำหรับจำนวนส่วนตั้งแต่ 2 ถึง k
        for p in 2..=k {
            for i in p - 1..n {  // ต้องมีอย่างน้อย p ตัวอักษร
                for j in p - 2..i {  // j คือตำแหน่งสุดท้ายของส่วนก่อนหน้า
                    if dp[j][p - 1] != i32::MAX {
                        dp[i][p] = dp[i][p].min(dp[j][p - 1] + cost[j + 1][i]);
                    }
                }
            }
        }
        
        dp[n - 1][k]
    }
}