bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize) {
    // ใช้จุดแรกและจุดที่สองเป็นฐาน
    int x0 = coordinates[0][0];
    int y0 = coordinates[0][1];
    int x1 = coordinates[1][0];
    int y1 = coordinates[1][1];
    
    // คำนวณความแตกต่างของจุดฐาน
    int dx = x1 - x0;
    int dy = y1 - y0;
    
    // ตรวจสอบทุกจุดเริ่มจากจุดที่ 3
    for (int i = 2; i < coordinatesSize; i++) {
        int xi = coordinates[i][0];
        int yi = coordinates[i][1];
        
        // ใช้สูตร cross multiplication เพื่อหลีกเลี่ยงการหาร
        // (yi - y0) * dx == (xi - x0) * dy
        // หรือ (yi - y0) * (x1 - x0) == (xi - x0) * (y1 - y0)
        if ((yi - y0) * dx != (xi - x0) * dy) {
            return false;
        }
    }
    
    return true;
}