class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int x_loc = location[0];
        int y_loc = location[1];
        vector<double> angles;
        int samePoint = 0;
        
        // แปลงแต่ละจุดเป็นมุม
        for (auto& p : points) {
            int x = p[0], y = p[1];
            
            // จุดที่อยู่ตำแหน่งเดียวกับ location
            if (x == x_loc && y == y_loc) {
                samePoint++;
                continue;
            }
            
            // คำนวณมุมเป็นเรเดียน แล้วแปลงเป็นองศา
            double rad = atan2(y - y_loc, x - x_loc);  // คืนค่า -π ถึง π (-180° ถึง 180°) 
            // ถ้า atan(y/x)คืนค่าเฉพาะ -π/2 ถึง π/2 (-90° ถึง 90°) 
            double deg = rad * 180.0 / M_PI;
            angles.push_back(deg);
        }
        
        // เรียงลำดับมุม
        sort(angles.begin(), angles.end());
        
        // ทำ duplicate เพื่อจัดการ wrap-around (มุม 359° + 2° = 361° ควรมองเป็น 1°)
        int n = angles.size();
        vector<double> doubled = angles;
        for (int i = 0; i < n; i++) {
            doubled.push_back(angles[i] + 360.0);
        }
        
        // Sliding window หามุมที่แตกต่างกันไม่เกิน angle
        int maxCount = 0;
        int j = 0;
        
        for (int i = 0; i < n; i++) {
            while (j < doubled.size() && doubled[j] - doubled[i] <= angle) {
                j++;
            }
            maxCount = max(maxCount, j - i);
        }
        
        return maxCount + samePoint;
    }
};