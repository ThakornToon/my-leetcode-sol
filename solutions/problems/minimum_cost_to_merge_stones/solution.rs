impl Solution {
    pub fn merge_stones(stones: Vec<i32>, k: i32) -> i32 {
        let n = stones.len();
        let k = k as usize;
        
        if (n - 1) % (k - 1) != 0 {
            return -1;
        }
        
        // Prefix sum
        let mut prefix = vec![0; n + 1];
        for (i, &stone) in stones.iter().enumerate() {
            prefix[i + 1] = prefix[i] + stone;
        }
        
        // dp[i][j] = min cost ในการรวม stones[i..j] ให้มีกองน้อยที่สุดเท่าที่เป็นไปได้
        let mut dp = vec![vec![0; n]; n];
        
        // เริ่มคิดจากการรวมก้อนที่เล็กที่สุดที่เป็นไปได้
        for len in k..=n {
            // ตำแหน่งเริ่มต้นในการรวม 
            for i in 0..=(n - len) {
                let j = i + len - 1;
                dp[i][j] = i32::MAX;
                
                // คิดการแบ่งส่วนย่อยที่เป็นไปได้
                for m in (i..j).step_by(k - 1) {
                    dp[i][j] = dp[i][j].min(dp[i][m] + dp[m + 1][j]);
                }
                
                // ถ้าสามารถ merge เป็น 1 กองได้จะรวมตั้งแต่ i...j (แบ่งส่วนคิดการรวมก่้่่อนย่อยเพื่อหากรณีดีที่สุดก่อนรวมรอบสุดท้ายเป็นก้อนเดียว)
                if (len - 1) % (k - 1) == 0 {
                    dp[i][j] += prefix[j + 1] - prefix[i];
                }
            }
        }
        
        dp[0][n - 1]
    }
}