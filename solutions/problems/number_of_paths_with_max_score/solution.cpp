class Solution {
private:
    const int MOD = 1000000007;
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        
        // dp[i][j] = {maxScore, count}
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {-1, 0}));
        
        // เริ่มต้นที่จุด S
        dp[n-1][n-1] = {0, 1};
        
        // วนลูปจากล่างขึ้นบน, ขวาไปซ้าย
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                // ข้ามถ้าเป็นอุปสรรค
                if (board[i][j] == 'X' || dp[i][j].first == -1) {
                    continue;
                }
                
                // คะแนนของ cell ปัจจุบัน
                int currentScore = 0;
                if (board[i][j] >= '0' && board[i][j] <= '9') {
                    currentScore = board[i][j] - '0';
                }
                
                // ลองเคลื่อนที่ไป 3 ทิศทาง
                vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {-1, -1}};
                
                for (auto& dir : dirs) {
                    int ni = i + dir.first;
                    int nj = j + dir.second;
                    
                    if (ni < 0 || nj < 0) continue;
                    
                    int newScore = dp[i][j].first + currentScore;
                    
                    // อัปเดต dp[ni][nj]
                    if (dp[ni][nj].first < newScore) {
                        dp[ni][nj].first = newScore;
                        dp[ni][nj].second = dp[i][j].second;
                    } else if (dp[ni][nj].first == newScore) {
                        dp[ni][nj].second = (dp[ni][nj].second + dp[i][j].second) % MOD;
                    }
                }
            }
        }
        
        // ผลลัพธ์ที่จุด E
        if (dp[0][0].first == -1) {
            return {0, 0};
        }
        return {dp[0][0].first, dp[0][0].second % MOD};
    }
};