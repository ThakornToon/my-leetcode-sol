impl Solution {
    pub fn predict_the_winner(nums: Vec<i32>) -> bool {
        let n = nums.len();
        let mut dp = vec![0; n]; // dp[i] การเลือกที่เริ่มจาก i ถึง j ด้วยความยาวต่างๆได้ค่า P1 - P2 ที่ดีที่สุดทั้งสองฝ่าย

        // กรณีเหลือตัวเลือกเดียว
        for i in 0..n {
            dp[i] = nums[i];
        }

        // เริ่มคิดจากความยาว 2..=n โดยเริ่มที่ตำแหน่ง i
        for length in 2..=n {
            for i in 0..=(n - length) {
                let j = i + length - 1;
                // เริ่มที่ i ความยาว l พิจารณาจาก
                // 1. เริ่มที่ i ความยาว l - 1
                // 2. เริ่มที่ i + 1 ความยาว l - 1
                dp[i] = (nums[i] - dp[i + 1]).max(nums[j] - dp[i]);
            }
        }

        return dp[0] >= 0;
    }
}