class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<long long, int> edgeCount;
        int maxCount = 0;
        
        for (const auto& row : wall) {
            long long sum = 0;
            for (int i = 0; i < row.size() - 1; i++) {
                sum += row[i];
                edgeCount[sum]++; // ที่ตำแหน่งนี้เป็นขอบของอิฐ
                maxCount = max(maxCount, edgeCount[sum]);
            }
        }
        // ต้องการ maxCount ที่มากที่สุดเพราะจะตัดอิฐน้อยที่สุด
        return wall.size() - maxCount; 
    }
};