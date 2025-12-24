bool carPooling(int** trips, int tripsSize, int* tripsColSize, int capacity) {
    // เนื่องจากตำแหน่งสูงสุดคือ 1000
    int changes[1001] = {0};
    
    // สร้าง difference array
    for (int i = 0; i < tripsSize; i++) {
        int num = trips[i][0];
        int from = trips[i][1];
        int to = trips[i][2];
        
        changes[from] += num;      // ขึ้นรถ
        changes[to] -= num;        // ลงรถ
    }
    
    // คำนวณ prefix sum และตรวจสอบ capacity
    int current = 0;
    for (int i = 0; i <= 1000; i++) {
        current += changes[i];
        if (current > capacity) {
            return false;
        }
    }
    
    return true;
}