bool isBoomerang(int** points, int pointsSize, int* pointsColSize) {
    // พื้นที่สามเหลี่ยม = ½ |(B-A) × (C-A)| ถ้าพื้นที่ ≠ 0 → ไม่ collinear
    int x1 = points[0][0], y1 = points[0][1];
    int x2 = points[1][0], y2 = points[1][1];
    int x3 = points[2][0], y3 = points[2][1];
    
    // ตรวจสอบว่าจุดซ้ำกันหรือไม่
    if ((x1 == x2 && y1 == y2) ||
        (x1 == x3 && y1 == y3) ||
        (x2 == x3 && y2 == y3)) {
        return false;
    }
    
    // ใช้ cross product
    // (x2-x1)*(y3-y1) != (x3-x1)*(y2-y1)
    int cross = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
    return cross != 0;
}