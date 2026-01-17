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
    public long largestSquareArea(int[][] bottomLeft, int[][] topRight) {
        int n = bottomLeft.length;
        long maxArea = 0;
        
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
                int left = Math.max(a1, a2);
                int bottom = Math.max(b1, b2);
                int right = Math.min(c1, c2);
                int top = Math.min(d1, d2);
                
                // ตรวจสอบว่ามีการตัดกัน
                if (left < right && bottom < top) {
                    int width = right - left;
                    int height = top - bottom;
                    long side = Math.min(width, height);
                    long area = side * side;
                    
                    maxArea = Math.max(maxArea, area);
                }
            }
        }
        
        return maxArea;
    }
}