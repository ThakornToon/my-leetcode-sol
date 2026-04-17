
// ทิศทาง: 0=ซ้าย, 1=ขวา, 2=บน, 3=ล่าง
int dirs[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

// nextDir[type][incoming_direction] = outgoing_direction
int nextStep[7][4] = {
    {4, 4, 4, 4},
    {1, 0, 4, 4}, // 1: ซ้าย<->ขวา (เข้า 0 ออก 1 / เข้า 1 ออก 0)
    {4, 4, 3, 2}, // 2: บน<->ล่าง (เข้า 2 ออก 3 / เข้า 3 ออก 2)
    {3, 4, 4, 0}, // 3: ซ้าย<->ล่าง (เข้า 0 ออก 3 / เข้า 3 ออก 0) *** แก้ตรงนี้จาก 1 เป็น 0 ***
    {4, 3, 4, 1}, // 4: ขวา<->ล่าง (เข้า 1 ออก 3 / เข้า 3 ออก 1) *** แก้ตรงนี้จาก 0 เป็น 1 ***
    {2, 4, 0, 4}, // 5: ซ้าย<->บน (เข้า 0 ออก 2 / เข้า 2 ออก 0)
    {4, 2, 1, 4}  // 6: ขวา<->บน (เข้า 1 ออก 2 / เข้า 2 ออก 1)
};

// เช็คว่าท่อแต่ละแบบ มี "รู" เปิดไปทางทิศไหนบ้าง
bool hasOpening(int type, int dir) {
    if (type == 1) return dir == 0 || dir == 1;
    if (type == 2) return dir == 2 || dir == 3;
    if (type == 3) return dir == 0 || dir == 3;
    if (type == 4) return dir == 1 || dir == 3;
    if (type == 5) return dir == 0 || dir == 2;
    if (type == 6) return dir == 1 || dir == 2;
    return false;
}

bool hasValidPath(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];
    if (m == 1 && n == 1) return true;

    int startType = grid[0][0];
    
    // ประกาศไว้ข้างนอก จอง Memory บน Stack แค่ครั้งเดียว (ขนาด ~90KB ปลอดภัยหายห่วง)
    bool visited[301][301];
    
    // ลองทุกทิศที่ (0,0) เปิดรูทิ้งไว้
    for (int d = 0; d < 4; d++) {
        if (!hasOpening(startType, d)) continue;

        int r = 0, c = 0;
        int outDir = d;
        
        // เคลียร์ค่า visited เฉพาะขนาดของ grid ปัจจุบัน (เร็วกว่า memset เต็มก้อน)
        for(int i = 0; i < m; i++) {
            memset(visited[i], 0, n * sizeof(bool));
        }
        
        visited[0][0] = true;

        while (1) {
            int nr = r + dirs[outDir][0];
            int nc = c + dirs[outDir][1];

            // เช็คขอบเขต
            if (nr < 0 || nr >= m || nc < 0 || nc >= n || visited[nr][nc]) break;

            // ทิศที่เรา "เข้า" ไปยังช่องใหม่ (ตรงข้ามกับทิศที่ออกจากช่องเก่า)
            int inDir = (outDir % 2 == 0) ? outDir + 1 : outDir - 1;
            int nType = grid[nr][nc];

            // ถ้าช่องถัดไปไม่มีรูรับทิศที่เรามา ให้หยุด
            if (!hasOpening(nType, inDir)) break;

            // ถ้าเชื่อมต่อกันได้และเป็นช่องสุดท้าย
            if (nr == m - 1 && nc == n - 1) return true;

            // เดินต่อไป
            visited[nr][nc] = true;
            r = nr;
            c = nc;
            outDir = nextStep[nType][inDir];
            if (outDir == 4) break;
        }
    }

    return false;
}