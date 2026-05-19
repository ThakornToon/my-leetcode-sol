class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int, int>> players; // (age, score)
        
        for (int i = 0; i < n; i++) {
            players.push_back({ages[i], scores[i]});
        }
        
        // เรียงตามอายุ (ถ้าอายุเท่ากันเรียงตามคะแนน)
        sort(players.begin(), players.end());
        
        vector<int> dp(n, 0);
        int maxScore = 0;
        
        for (int i = 0; i < n; i++) {
            dp[i] = players[i].second;
            for (int j = 0; j < i; j++) {
                // ถ้าคะแนน i >= คะแนน j (ไม่มี conflict)
                if (players[i].second >= players[j].second) {
                    dp[i] = max(dp[i], dp[j] + players[i].second);
                }
            }
            maxScore = max(maxScore, dp[i]);
        }
        
        return maxScore;
    }
};