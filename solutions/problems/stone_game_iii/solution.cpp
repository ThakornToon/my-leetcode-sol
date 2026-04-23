class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        // คิดจากหลังมาหน้าว่า Alice จะขนะไหม
        vector<int> dp(n + 1, 0);
        
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = INT_MIN;
            int sum = 0;
            
            // ลองหยิบมากสุดสามก้อนเริ่มที่ตำแหน่ง i
            for (int k = 1; k <= 3 && i + k - 1 < n; k++) {
                sum += stoneValue[i + k - 1];
                // Alice - Bob ที่ดีที่สุด
                dp[i] = max(dp[i], sum - dp[i + k]);
            }
        }
        
        if (dp[0] > 0) return "Alice";
        if (dp[0] < 0) return "Bob";
        return "Tie";
    }
};