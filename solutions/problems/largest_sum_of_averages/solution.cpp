class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> prefix(n + 1, 0.0);
        
        // prefix sums
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        
        // DP array: dp[i][k] ผลรวมสูงสุดเมื่อแบ่ง i ตัวแรกเป็น k กลุ่ม
        vector<vector<double>> dp(n + 1, vector<double>(k + 1, 0.0));
        
        // แบ่งเป็นกลุ่มเดียว
        for (int i = 1; i <= n; i++) {
            dp[i][1] = prefix[i] / i;
        }
        
        // แบ่งตั้งแต่ 2..=k กลุ่ม
        for (int group = 2; group <= k; group++) { 
            // ลองแบ่งกลุ่มถัดมาตั้งแต่ j ถึง i           
            for (int i = group - 1; i <= n; i++) {
                for (int j = group - 1; j <= i; j++) {
                    double avg = (prefix[i] - prefix[j - 1]) / (i - j + 1);
                    dp[i][group] = max(dp[i][group], dp[j - 1][group - 1] + avg);
                }
            }
        }
        
        return dp[n][k];
    }
};