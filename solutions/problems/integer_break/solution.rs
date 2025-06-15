impl Solution {
    pub fn integer_break(n: i32) -> i32 {
        let n = n as usize;
    let mut dp = vec![0; n + 1]; // index แทนตัวเลขนั้นๆ ส่วนค่าในแต่ละ index คือค่าสูงสุดที่แบ่งแล้วคูณมาได้
    dp[1] = 1; // เลข 1 ไม่สามารถแบ่งได้
    
    // ทำแบบ bottom up
    for i in 2..=n {
        for j in 1..i { // ลองแบ่ง i เป็น j และ i-j สำหรับทุก j จาก 1 ถึง i-1
            let max_j = j.max(dp[j]); // เลือกระหว่างใช้ j ตรงๆ หรือใช้ผลลัพธ์จากการแบ่ง j
            let max_ij = (i - j).max(dp[i - j]);
            dp[i] = dp[i].max(max_j * max_ij); // เก็บค่าสูงสุดจากการแบ่ง i
        }
    }
    
    dp[n] as i32
    }
}