/*
หาคู่จุด (i, j) ทุกคู่ที่เป็นไปได้
สำหรับแต่ละคู่ คำนวณ:
1. จุดกึ่งกลาง (mid_x, mid_y)
2. ความยาวของเส้นทแยงมุม
3. ใช้ map<midpoint, map<length, vector<point pairs>> เพื่อจัดกลุ่ม
4. สำหรับกลุ่มที่มีจุดกึ่งกลางและความยาวเส้นทแยงมุมเหมือนกัน คู่จุดในกลุ่มนั้นสามารถสร้างสี่เหลี่ยมได้
5. คำนวณพื้นที่จากจุด 4 จุด
6. หาพื้นที่น้อยที่สุด
*/
class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        int n = points.size();
        if (n < 4) return 0;
        
        double minArea = numeric_limits<double>::max();
        unordered_map<string, vector<pair<int, int>>> map; 
        // key: mid_x,mid_y,length 
        // value: {pair of points index}
        
        // เก็บคู่จุดทั้งหมด
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double mid_x = (points[i][0] + points[j][0]) / 2.0;
                double mid_y = (points[i][1] + points[j][1]) / 2.0;
                double length = dist(points[i], points[j]);
                
                string key = to_string(mid_x) + "," + to_string(mid_y) + "," + to_string(length);
                map[key].push_back({i, j});
            }
        }
        
        // ตรวจสอบแต่ละกลุ่ม
        for (auto& [key, pairs] : map) {
            int m = pairs.size();
            if (m < 2) continue;
            
            // สำหรับแต่ละคู่ในกลุ่มเดียวกัน
            for (int a = 0; a < m; a++) {
                for (int b = a + 1; b < m; b++) {
                    int i1 = pairs[a].first, j1 = pairs[a].second;
                    int i2 = pairs[b].first, j2 = pairs[b].second;
                    
                    // จุด 4 จุด: i1, i2, j2, j1
                    vector<int>& p1 = points[i1];
                    vector<int>& p2 = points[i2];
                    vector<int>& p3 = points[j2];
                    vector<int>& p4 = points[j1];
                    
                    // คำนวณพื้นที่ (i1, i2, j2, j1)
                    double area = calculateArea(p1, p2, p3, p4);
                    minArea = min(minArea, area);
                    
                }
            }
        }
        
        return minArea == numeric_limits<double>::max() ? 0 : minArea;
    }
private:
    double dist(vector<int>& p1, vector<int>& p2) {
        double dx = p1[0] - p2[0];
        double dy = p1[1] - p2[1];
        return dx * dx + dy * dy; // คืนค่ารูปแบบกำลังสอง
    }
    
    double calculateArea(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        // AB และ AC เป็นด้านประชิด พื้นที่ = |AB × AC|
        double area = abs((p2[0] - p1[0]) * (p3[1] - p2[1]) - 
                         (p2[1] - p1[1]) * (p3[0] - p2[0]));
        return area;
    }
};