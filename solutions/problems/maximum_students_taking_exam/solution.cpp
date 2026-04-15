class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int m = seats.size();
        int n = seats[0].size();
        int maxMask = 1 << n;
        
        // สร้าง mask สำหรับที่นั่งเสียในแต่ละแถว 1 คือนั่งไม่ได้
        vector<int> broken(m, 0);
        for (int i = 0; i < m; i++) {
            int mask = 0;
            for (int j = 0; j < n; j++) {
                if (seats[i][j] == '#') {
                    mask |= (1 << j);
                }
            }
            broken[i] = mask;
        }
        
        // dp[i][mask] = max students ในแถว i ด้วย mask นี้
        vector<vector<int>> dp(m + 1, vector<int>(maxMask, -1));
        dp[0][0] = 0;
        
        // ฟังก์ชันนับจำนวน bit ที่เป็น 1
        auto countBits = [](int x) {
            return __builtin_popcount(x);
        };
        
        for (int i = 0; i < m; i++) {
            for (int prevMask = 0; prevMask < maxMask; prevMask++) {
                if (dp[i][prevMask] == -1) continue;
                
                // ลองทุก mask ที่เป็นไปได้
                for (int mask = 0; mask < maxMask; mask++) {
                    // ตรวจสอบที่นั่งเสีย
                    if ((mask & broken[i]) != 0) continue;
                    
                    // ตรวจสอบแนวนอน: ไม่มี 1 ติดกัน
                    if ((mask & (mask << 1)) != 0) continue;
                    
                    // ตรวจสอบแนวทแยงกับแถวก่อนหน้า
                    if ((prevMask & (mask << 1)) != 0) continue;
                    if ((prevMask & (mask >> 1)) != 0) continue;
                    
                    int cnt = countBits(mask);
                    dp[i + 1][mask] = max(dp[i + 1][mask], dp[i][prevMask] + cnt);
                }
            }
        }
        
        int result = 0;
        for (int mask = 0; mask < maxMask; mask++) {
            result = max(result, dp[m][mask]);
        }
        
        return result;
    }
};


