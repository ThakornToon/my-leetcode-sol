class Solution {
public:
    int palindromePartition(string s, int k) {
        int n = s.length();
        
        // cost[i][j] = จำนวนการเปลี่ยนเพื่อทำให้ s[i..j] เป็น palindrome
        vector<vector<int>> cost(n, vector<int>(n, 0));
        
        // คำนวณ cost สำหรับทุก substring
        // เริ่มจากความยาว 2 ขึ้นไป (ความยาว 1 ไม่ต้องเปลี่ยน)
        for (int length = 2; length <= n; length++) {
            for (int i = 0; i + length <= n; i++) {
                int j = i + length - 1;
                // ถ้าตัวแรกและตัวสุดท้ายต่างกัน ต้องเปลี่ยน 1 ตัว
                // บวกกับ cost ของ substring ข้างใน (i+1 ถึง j-1)
                cost[i][j] = cost[i + 1][j - 1] + (s[i] != s[j] ? 1 : 0);
            }
        }
        
        // dp[i][p] = min cost สำหรับ s[0..i] แบ่งเป็น p ส่วน
        // ใช้ INT_MAX สำหรับค่าที่ยังไม่สามารถทำได้
        vector<vector<int>> dp(n, vector<int>(k + 1, INT_MAX));
        
        // Base case: แบ่งเป็น 1 ส่วน = cost[0][i]
        for (int i = 0; i < n; i++) {
            dp[i][1] = cost[0][i];
        }
        
        // คำนวณ DP สำหรับจำนวนส่วนตั้งแต่ 2 ถึง k
        for (int p = 2; p <= k; p++) {
            for (int i = p - 1; i < n; i++) {  // ต้องมีอย่างน้อย p ตัวอักษร
                for (int j = p - 2; j < i; j++) {  // j คือตำแหน่งสุดท้ายของส่วนก่อนหน้า
                    // s[0..j..i] แบ่งเป็น p ส่วน
                    if (dp[j][p - 1] != INT_MAX) {
                        dp[i][p] = min(dp[i][p], dp[j][p - 1] + cost[j + 1][i]);
                    }
                }
            }
        }
        
        return dp[n - 1][k];
    }
};