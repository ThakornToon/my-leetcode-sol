int min(int a, int b) {
    return a < b ? a : b;
}

// ฟังก์ชันเช็คว่าสามารถทำให้แถวบนหรือล่างเป็น target ได้หรือไม่
// และหาจำนวนการหมุนขั้นต่ำ
int check(int target, int* tops, int* bottoms, int n) {
    int rotations_top = 0; // หมุนเพื่อให้ tops ทั้งหมดเป็น target
    int rotations_bottom = 0; // หมุนเพื่อให้ bottoms ทั้งหมดเป็น target
    
    for (int i = 0; i < n; i++) {
        // ถ้า domino ตัวนี้ไม่มี target เลย
        if (tops[i] != target && bottoms[i] != target) {
            return INT_MAX;
        }
        
        // ถ้า tops[i] ไม่ใช่ target ต้องหมุน
        if (tops[i] != target) {
            rotations_top++;
        }
        
        // ถ้า bottoms[i] ไม่ใช่ target ต้องหมุน
        if (bottoms[i] != target) {
            rotations_bottom++;
        }
    }
    
    return min(rotations_top, rotations_bottom);
}

int minDominoRotations(int* tops, int topsSize, int* bottoms, int bottomsSize) {
    int rotations = INT_MAX;
    
    // ลองตัวเลือกที่ 1: ทำให้แถวบนหรือล่างเป็น tops[0]
    rotations = min(rotations, check(tops[0], tops, bottoms, topsSize));
    
    // ลองตัวเลือกที่ 2: ทำให้แถวบนหรือล่างเป็น bottoms[0]
    rotations = min(rotations, check(bottoms[0], tops, bottoms, topsSize));
    
    return rotations == INT_MAX ? -1 : rotations;
}
