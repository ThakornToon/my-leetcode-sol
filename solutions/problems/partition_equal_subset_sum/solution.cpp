class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum % 2 != 0) {
            return false;
        }
        int target = sum / 2;
        vector<bool> dp(target + 1, false); // ดูว่าสร้างเลขนั้นๆได้ไหม
        dp[0] = true;
        for (int num : nums) {
            for (int i = target; i - num >= 0; i--) {
                if (dp[i - num] == true) {
                    dp[i] = true;
                }
            }
        }
        return dp[target];
    }
};