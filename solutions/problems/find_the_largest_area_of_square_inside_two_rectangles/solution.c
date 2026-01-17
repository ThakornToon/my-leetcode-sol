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
int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

long long largestSquareArea(int** bottomLeft, int bottomLeftSize, int* bottomLeftColSize, int** topRight, int topRightSize, int* topRightColSize) {
    int n = bottomLeftSize;
    long long maxSide = 0;  // ใช้ long long เพื่อป้องกัน overflow
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // คำนวณความกว้างและความสูงของพื้นที่ตัดกัน
            int w = min(topRight[i][0], topRight[j][0]) - 
                    max(bottomLeft[i][0], bottomLeft[j][0]);
            int h = min(topRight[i][1], topRight[j][1]) - 
                    max(bottomLeft[i][1], bottomLeft[j][1]);
            
            // ด้านของสี่เหลี่ยมจัตุรัสคือค่าน้อยสุดระหว่าง w และ h
            int side = min(w, h);
            
            // ถ้า side > 0 หมายถึงมีพื้นที่ตัดกัน
            if (side > 0) {
                if (side > maxSide) {
                    maxSide = side;
                }
            }
        }
    }
    
    // คืนค่าพื้นที่ = ด้าน²
    return maxSide * maxSide;
}