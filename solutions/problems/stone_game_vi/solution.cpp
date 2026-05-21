class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        // เลือกหินที่มีค่า aliceValue[i] + bobValue[i] มากที่สุด 
        // เพราะการเลือกหินนั้นจะได้คะแนนตัวเองและแย่งคะแนนคู่แข่ง
        int n = aliceValues.size();
        vector<pair<int, int>> stones; // (sum, index)
        
        for (int i = 0; i < n; i++) {
            stones.push_back({aliceValues[i] + bobValues[i], i});
        }
        
        // เรียงตาม sum จากมากไปน้อย
        sort(stones.begin(), stones.end(), greater<pair<int, int>>());
        
        int aliceScore = 0, bobScore = 0;
        
        for (int i = 0; i < n; i++) {
            int idx = stones[i].second;
            if (i % 2 == 0) {
                aliceScore += aliceValues[idx];
            } else {
                bobScore += bobValues[idx];
            }
        }
        
        if (aliceScore > bobScore) return 1;
        if (aliceScore < bobScore) return -1;
        return 0;
    }
};