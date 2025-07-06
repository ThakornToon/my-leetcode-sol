class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // เรียงลำดับตามจุดสิ้นสุดก่อนไปหลัง
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int arrows = 1;  
        int end = points[0][1]; // ยิงที่จุดสุดท้าย
        
        for (int i = 1; i < points.size(); ++i) {
            // ถ้าจุดเริ่มของบอลลูนปัจจุบันมากกว่าจุดสิ้นสุดของลูกศรปัจจุบัน
            if (points[i][0] > end) {
                arrows++;
                end = points[i][1];
            }
        }
        
        return arrows;
    }
};