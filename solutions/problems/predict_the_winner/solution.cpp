class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n); // dp[i] การเลือกที่เริ่มจาก i ถึง j ด้วยความยาวต่างๆได้ค่า P1 - P2 ที่ดีที่สุดทั้งสองฝ่าย

        // กรณีเหลือตัวเลือกเดียว
        for (int i = 0; i < n; i++) {
            dp[i] = nums[i];
        }

        // เริ่มคิดจากความยาว 2..=n โดยเริ่มที่ตำแหน่ง i
        for (int length = 2; length <= n; length++) {
            for (int i = 0; i <= n - length; i++) {
                int j = i + length - 1;
                // เริ่มที่ i ความยาว l พิจารณาจาก
                // 1. เริ่มที่ i ความยาว l - 1
                // 2. เริ่มที่ i + 1 ความยาว l - 1
                dp[i] = max(nums[i] - dp[i + 1], nums[j] - dp[i]);
            }
        }

        return dp[0] >= 0;
    }
};