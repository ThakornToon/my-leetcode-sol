class Solution {
private:
    int dist(int from, int to) {
        // from อาจเป็น 26 หมายถึงยังไม่ได้วางนิ้ว
        if (from == 26) return 0;
        int x1 = from / 6;
        int y1 = from % 6;
        int x2 = to / 6;
        int y2 = to % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }
public:
    int minimumDistance(string word) {
        int n = word.size();
        // ใช้ 27 เพราะ 26 หมายถึงยังไม่ได้วางนิ้ว
        vector<vector<vector<int>>> dp(n + 1, 
            vector<vector<int>>(27, vector<int>(27, INT_MAX / 2)));

        // เริ่มต้น: ยังไม่ได้วางนิ้วทั้งสอง
        dp[0][26][26] = 0;
        
        for (int i = 0; i < n; i++) {
            int target = word[i] - 'A';
            for (int f1 = 0; f1 <= 26; f1++) {
                for (int f2 = 0; f2 <= 26; f2++) {
                    if (dp[i][f1][f2] == INT_MAX / 2) continue;
                    
                    // ใช้นิ้ว 1 พิมพ์
                    dp[i + 1][target][f2] = min(dp[i + 1][target][f2],
                        dp[i][f1][f2] + dist(f1, target));
                    
                    // ใช้นิ้ว 2 พิมพ์
                    dp[i + 1][f1][target] = min(dp[i + 1][f1][target],
                        dp[i][f1][f2] + dist(f2, target));
                }
            }
        }
        
        int result = INT_MAX;
        for (int f1 = 0; f1 <= 26; f1++) {
            for (int f2 = 0; f2 <= 26; f2++) {
                result = min(result, dp[n][f1][f2]);
            }
        }
        return result;
    }
};