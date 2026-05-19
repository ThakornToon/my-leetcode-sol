class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        // สร้าง vector สำหรับเก็บ x-coordinates
        vector<int> xCoords;
        for (auto& point : points) {
            xCoords.push_back(point[0]);
        }
        
        // เรียงลำดับ x-coordinates
        sort(xCoords.begin(), xCoords.end());
        
        // หา difference ที่มากที่สุดระหว่าง x ที่ติดกัน
        int maxWidth = 0;
        for (int i = 1; i < xCoords.size(); i++) {
            maxWidth = max(maxWidth, xCoords[i] - xCoords[i-1]);
        }
        
        return maxWidth;
    }
};