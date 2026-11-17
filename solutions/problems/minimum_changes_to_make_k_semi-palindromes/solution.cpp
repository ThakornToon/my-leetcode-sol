class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.length();
        
        // cost[i][j] เก็บต้นทุนที่น้อยที่สุดในการทำให้ s[i...=j] เป็น semi-palindrome จากการแบ่งด้วยระยะ d ทั้งหมดที่เป็นไปได้
        vector<vector<int>> cost(n, vector<int>(n, INT_MAX));
        
        // คำนวณจำนวนการเปลี่ยนแปลงให้เป็น palindrome สำหรับสตริงย่อยที่น้อยที่สุดจากการแบ่งด้วยระยะ d 
        auto get_cost = [&](int i, int j, int d) {
            int total_changes = 0;
            int len = j - i + 1;
            // วนลูปตามกลุ่ม semi
            for (int start = 0; start < d; ++start) {
                // คำนวณจำนวนสมาชิกในกลุ่มย่อยนี้
                int count = (len / d);
                // ตรวจสอบตัวอักษรหัวและท้ายของกลุ่มย่อยพร้อมกัน
                for (int l = 0, r = count - 1; l < r; ++l, --r) {
                    int idx1 = i + start + l * d;
                    int idx2 = i + start + r * d;
                    if (s[idx1] != s[idx2]) {
                        total_changes++;
                    }
                }
            }
            return total_changes;
        };
        
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                int len = j - i + 1;
                for (int d = 1; d <= len / 2; ++d) {
                    if (len % d == 0) {
                        cost[i][j] = min(cost[i][j], get_cost(i, j, d));
                    }
                }
            }
        }
        
        // dp[i][k] คือต้นทุนขั้นต่ำในการแบ่ง s[i...=n-1] ออกเป็น k ส่วน
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX));
        dp[n][0] = 0;
        
        for (int p = 1; p <= k; ++p) {
            // พิจารณา s[i...=j]
            for (int i = n - 1; i >= 0; i--) {
                for (int j = i; j < n; j++) {
                    if (cost[i][j] != INT_MAX && dp[j + 1][p - 1] != INT_MAX) {
                        dp[i][p] = min(dp[i][p], cost[i][j] + dp[j + 1][p - 1]);
                    }
                }
            }
        }
        
        return dp[0][k];
    }
};