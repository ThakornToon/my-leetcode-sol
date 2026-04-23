class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        // default น้อยไปมาก
        sort(satisfaction.begin(), satisfaction.end());
        
        int n = satisfaction.size();
        
        // dp[i][j] เมื่อพิจารณาจากตัวมากสุดลงมาถึง i โดยใช้เวลา t
        vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0));
        
        for (int i = n - 1; i >= 0; i--) {
            // ตัวปัจจุบันอาจเป็น t ได้หลายค่าในกรณีต่างๆ
            for (int t = 1; t <= n; t++) {
                // ไม่เอาตัวปัจจุบัน หรือ เอาตัวปัจจุบัน
                dp[i][t] = max(dp[i + 1][t], satisfaction[i] * t + dp[i + 1][t + 1]);
            }
        }
        
        // เมื่อกลับมาถึงจุดเริ่มต้นแล้วได้กรณีที่ดีที่สุด
        return dp[0][1];
    }
};