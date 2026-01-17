/*
1. หาพื้นที่ตัดกันของทุกคู่สี่เหลี่ยม
สำหรับสี่เหลี่ยม i และ j:
พื้นที่ตัดกัน = [max(a_i, a_j), max(b_i, b_j), min(c_i, c_j), min(d_i, d_j)]
ถ้า max(a_i, a_j) < min(c_i, c_j) และ max(b_i, b_j) < min(d_i, d_j) → มีการตัดกัน

2. หาขนาดสี่เหลี่ยมจัตุรัสสูงสุดในพื้นที่ตัดกัน
ถ้าพื้นที่ตัดกันคือ [x1, y1, x2, y2]:
ความกว้าง = x2 - x1
ความสูง = y2 - y1
ขนาดสี่เหลี่ยมจัตุรัสสูงสุด = min(ความกว้าง, ความสูง)
พื้นที่ = (min(ความกว้าง, ความสูง))²

3. เก็บค่าสูงสุดจากทุกคู่สี่เหลี่ยม
*/

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long maxArea = 0;
        
        // ตรวจสอบทุกคู่สี่เหลี่ยม
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // พิกัดของสี่เหลี่ยม i
                int a1 = bottomLeft[i][0], b1 = bottomLeft[i][1];
                int c1 = topRight[i][0], d1 = topRight[i][1];
                
                // พิกัดของสี่เหลี่ยม j
                int a2 = bottomLeft[j][0], b2 = bottomLeft[j][1];
                int c2 = topRight[j][0], d2 = topRight[j][1];
                
                // หาพื้นที่ตัดกัน
                int x1 = max(a1, a2);  // ซ้าย
                int y1 = max(b1, b2);  // ล่าง
                int x2 = min(c1, c2);  // ขวา
                int y2 = min(d1, d2);  // บน
                
                // ตรวจสอบว่ามีการตัดกันจริง
                if (x1 < x2 && y1 < y2) {
                    // คำนวณขนาดสี่เหลี่ยมจัตุรัสที่ใหญ่ที่สุด
                    int width = x2 - x1;
                    int height = y2 - y1;
                    long long side = min(width, height);  // ด้านของสี่เหลี่ยมจัตุรัส
                    long long area = side * side;
                    
                    maxArea = max(maxArea, area);
                }
            }
        }
        
        return maxArea;
    }
};