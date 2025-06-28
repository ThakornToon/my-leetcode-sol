impl Solution {
    pub fn can_cross(stones: Vec<i32>) -> bool {
        let stonesSize = stones.len();
        let mut dp = vec![vec![false; stonesSize + 1]; stonesSize]; // หินจำนวน stonesSize ระยะกระโดดที่เป็นไปได้มากสุดคือ 0..=stonesSize
        dp[0][1] = true; // หินก้อนแรกมีการกระโดดได้แค่ 1
        
        for i in 1..stonesSize { // ความเป็นไปได้ในการเดินทางไปยังหินก้อนที่ i 
            for j in 0..i { // ดูก้อนหินก่อนหน้านี้
                let diff = (stones[i] - stones[j]) as usize; // ระยะห่างระหว่างก้อนหิน
                if diff > stonesSize || !dp[j][diff] { // ดูจากหินก้อนที่แล้วว่าสามารถกระโดดในระยะนี้ได้ไหม แล้วถ้าระยะมากกว่า stonesSize ก็เป็นไปไม่ได้เลย
                    continue;
                }
                if i == stonesSize - 1 { // มาถึงก้อนสุดท้ายได้
                    return true;
                }
                // mark ระยะกระโดดออกที่เป็นไปได้
                dp[i][diff] = true;
                if diff - 1 >= 0 {
                    dp[i][diff - 1] = true;
                }
                if diff + 1 <= stonesSize {
                    dp[i][diff + 1] = true;
                }
            }
        }

        return false;

    }
}