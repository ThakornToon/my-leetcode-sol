class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        // ใช้ vector ขนาด n (เท่ากับแถวสุดท้าย)
        vector<int> dp = triangle.back(); // copy แถวสุดท้าย
        
        // คำนวณขึ้นไปทีละแถว
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
        }
        
        return dp[0];
    }
};