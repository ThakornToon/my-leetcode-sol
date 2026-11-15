class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        
        // dp[idx][diff] = จำนวนวิธีที่สร้าง subsequences ที่มี diff โดยพิจารณา idx เป็นสมาชิดตัวสุดท้าย
        vector<unordered_map<long long, int>> dp(n);
        int res = 0;
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long long diff = (long long)nums[i] - nums[j];
                int sum = 0;
                if (dp[j].find(diff) != dp[j].end()) {
                    sum = dp[j][diff];  // seq ความยาวตั้งแต่ 2 ขึ้นไป
                }
                dp[i][diff] += sum + 1;  // + 1 คือการสร้าง Subsequence คู่ใหม่ที่มีความยาวเท่ากับ 2 ระหว่าง nums[j] กับ nums[i]
                res += sum;
            }
        }
        
        return res;
    }
};