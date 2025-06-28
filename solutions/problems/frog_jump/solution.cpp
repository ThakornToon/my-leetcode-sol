class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> dp; // เก็บ step ที่เป็นไปได้ของแต่ละก้อน
        for (int stone : stones) {
            dp[stone] = unordered_set<int>();
        }
        dp[0].insert(0);
        
        for (int stone : stones) { // bottom up
            for (int step : dp[stone]) {
                for (int next_step : {step-1, step, step+1}) {
                    if (next_step > 0 && dp.count(stone + next_step)) {
                        dp[stone + next_step].insert(next_step);
                    }
                }
            }
        }
        
        return !dp[stones.back()].empty();
    }
};