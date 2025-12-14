class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size();
        int n = strs[0].size();
        
        // canFollow[i][j] = ตำแหน่งที่ i ถูกตามหลังด้วยตำแหน่ง j ได้ไหม
        vector<vector<bool>> canFollow(n, vector<bool>(n, true));
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // ดูทุกสตริง
                for (int k = 0; k < m; k++) {
                    if (strs[k][i] > strs[k][j]) {
                        canFollow[i][j] = false;
                        break;
                    }
                }
            }
        }
        
        // dp[i] = ความยาวสตริงมากที่สุดที่จบที่ column i ได้
        vector<int> dp(n, 1);
        int maxLis = 1;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // . . . j i
                if (canFollow[j][i] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    maxLis = max(maxLis, dp[i]);
                }
            }
        }

        // จำนวนการลบที่น้อยที่สุด
        return n - maxLis;
    }
};