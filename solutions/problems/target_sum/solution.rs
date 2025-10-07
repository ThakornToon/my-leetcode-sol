/*
sum = ผลรวมทั้งหมดของอาร์เรย์
P = ผลรวมของตัวเลขที่ใส่เครื่องหมาย '+'
N = ผลรวมของตัวเลขที่ใส่เครื่องหมาย '-'

จากเงื่อนไขโจทย์:
P + N = sum (เพราะตัวเลขทั้งหมดต้องถูกใช้)
P - N = target (ผลรวมสุดท้ายต้องเท่ากับ target)

2P = sum + target
∴ P = (sum + target) / 2
2N = sum - target
∴ N = (sum - target) / 2

P = (sum + target) / 2:
(sum + target) ต้องเป็นเลขคู่ (หาร 2 ลงตัว)
P ต้องเป็นจำนวนเต็มไม่ติดลบ
P ≤ sum (เพราะ P เป็นสับเซตของตัวเลขทั้งหมด)

หาจำนวนสับเซตที่มีผลรวมเท่ากับ P = (sum + target) / 2
dp[j] = จำนวนวิธีที่จะได้ผลรวม j โดยใช้ตัวเลขบางส่วนจากอาร์เรย์
*/

impl Solution {
    pub fn find_target_sum_ways(nums: Vec<i32>, target: i32) -> i32 {
        let sum: i32 = nums.iter().sum();
        
        // Check if target is achievable
        if target.abs() > sum || (sum + target) % 2 != 0 {
            return 0;
        }
        
        let subset_sum = ((sum + target) / 2) as usize;
        
        // DP array
        let mut dp = vec![0; subset_sum + 1];
        dp[0] = 1;
        
        for &num in &nums {
            let num = num as usize;
            for j in (num..=subset_sum).rev() {
                dp[j] += dp[j - num];
            }
        }
        
        dp[subset_sum]
    }
}