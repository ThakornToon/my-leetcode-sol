class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();

        // dp[i][j] = ผลรวม ascii ที่ลบไปเมื่อพิจารณา s1 ยาว i และ s2 ยาว j
        vector<int> prev(n + 1, 0);
        vector<int> curr(n + 1, 0);
        
        // Initialize first row
        // กรณีที่ i = 0
        for (int j = 1; j <= n; j++) {
            prev[j] = prev[j - 1] + s2[j - 1];
        }
        
        for (int i = 1; i <= m; i++) {
            // Initialize first column for current row
            // กรณีที่ j = 0
            curr[0] = prev[0] + s1[i - 1];
            
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    curr[j] = prev[j - 1];
                } else {
                    int deleteFromS1 = prev[j] + s1[i - 1];
                    int deleteFromS2 = curr[j - 1] + s2[j - 1];
                    curr[j] = min(deleteFromS1, deleteFromS2);
                }
            }
            
            // Move to next iteration
            swap(prev, curr);
        }
        
        return prev[n];
    }
};