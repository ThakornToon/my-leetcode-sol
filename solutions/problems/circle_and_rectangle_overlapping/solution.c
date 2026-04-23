// ฟังก์ชัน clamp: จำกัดค่าให้อยู่ในช่วง [min, max]
int clamp(int val, int min, int max) {
    if (val < min) return min;
    if (val > max) return max;
    return val;
}

bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
    // หาจุดที่ใกล้ที่สุดในสี่เหลี่ยม
    int closestX = clamp(xCenter, x1, x2);
    int closestY = clamp(yCenter, y1, y2);
    
    // คำนวณระยะทางจากศูนย์กลางวงกลมไปยัง closest point
    int dx = xCenter - closestX;
    int dy = yCenter - closestY;
    int distSquared = dx * dx + dy * dy;
    
    // เปรียบเทียบกับรัศมีกำลังสอง
    return distSquared <= radius * radius;
}