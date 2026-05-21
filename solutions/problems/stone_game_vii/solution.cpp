class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        
        // Prefix sum
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stones[i];
        }
        
        // dp[i][j] = คะแนน difference ที่ผู้เล่นที่กำลังจะเล่นจะได้จาก subarray stones[i..j]
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // คำนวณสำหรับช่วงความยาวต่างๆ
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                int sumLeft = prefix[j + 1] - prefix[i + 1]; // หินที่เหลือถ้าเลือก i
                int sumRight = prefix[j] - prefix[i];       // หินที่เหลือถ้าเลือก j
                
                int takeLeft = sumLeft - dp[i + 1][j];
                int takeRight = sumRight - dp[i][j - 1];
                
                dp[i][j] = max(takeLeft, takeRight);
            }
        }
        
        return dp[0][n - 1];
    }
};