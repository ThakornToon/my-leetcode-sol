class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();
        
        // dp[i][j] = คะแนนสูงสุดเมื่อเลือกจากซ้าย i ครั้ง และจากขวา j ครั้ง
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, INT_MIN));
        dp[0][0] = 0;
        
        // operation ที่ i
        for (int i = 0; i < m; i++) {
            // จากทุกความเป็นไปได้
            for (int left = 0; left <= i; left++) {
                int right = i - left;
                if (dp[left][right] == INT_MIN) continue;
                
                // ตัวคูณ operation ที่ i
                int mult = multipliers[i];
                
                // เลือกจากซ้าย
                int newLeft = left + 1;
                dp[newLeft][right] = max(dp[newLeft][right], 
                                         dp[left][right] + nums[left] * mult);
                
                // เลือกจากขวา
                int newRight = right + 1;
                dp[left][newRight] = max(dp[left][newRight],
                                         dp[left][right] + nums[n - 1 - right] * mult);
            }
        }
        
        int result = INT_MIN;
        // ดูว่าแบบไหนดีสุด
        for (int left = 0; left <= m; left++) {
            int right = m - left;
            result = max(result, dp[left][right]);
        }
        
        return result;
    }
};