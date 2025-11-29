class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        
        // เก็บตำแหน่งทั้งหมดที่เป็น 1
        vector<pair<int, int>> ones1, ones2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1) ones1.push_back({i, j});
                if (img2[i][j] == 1) ones2.push_back({i, j});
            }
        }
        
        // นับความถี่ของแต่ละการเลื่อน
        unordered_map<string, int> shiftCount;
        int maxOverlap = 0;
        
        for (auto& [r1, c1] : ones1) {
            for (auto& [r2, c2] : ones2) {
                // คำนวณการเลื่อนที่ต้องการ
                int dr = r2 - r1;
                int dc = c2 - c1;
                
                // ใช้ string เป็น key ใน map
                string key = to_string(dr) + "," + to_string(dc);
                shiftCount[key]++;
                
                maxOverlap = max(maxOverlap, shiftCount[key]);
            }
        }
        
        return maxOverlap;
    }
};