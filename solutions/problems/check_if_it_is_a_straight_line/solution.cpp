class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        
        // จุดน้อยกว่า 3 จุดจะเป็นเส้นตรงเสมอ
        if (n <= 2) return true;
        
        // เก็บพิกัดของจุดแรกและจุดที่สอง
        int x0 = coordinates[0][0], y0 = coordinates[0][1];
        int x1 = coordinates[1][0], y1 = coordinates[1][1];
        
        // คำนวณความแตกต่าง
        int dx = x1 - x0;
        int dy = y1 - y0;
        
        // ตรวจสอบทุกจุดที่เหลือ
        for (int i = 2; i < n; i++) {
            int xi = coordinates[i][0];
            int yi = coordinates[i][1];
            
            // สูตร: (yi - y0) * dx == (xi - x0) * dy
            // ใช้การคูณไขว้แทนการหารเพื่อหลีกเลี่ยงปัญหาจุดทศนิยม
            if ((yi - y0) * dx != (xi - x0) * dy) {
                return false;
            }
        }
        
        return true;
    }
};