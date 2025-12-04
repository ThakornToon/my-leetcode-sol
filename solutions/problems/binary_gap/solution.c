int binaryGap(int n) {
    int maxGap = 0;
    int lastPos = -1;  // ตำแหน่งสุดท้ายของ 1
    
    for (int i = 0; i < 32; i++) {
        // ตรวจสอบว่า bit ที่ i เป็น 1 หรือไม่
        if ((n >> i) & 1) {
            if (lastPos != -1) {
                // คำนวณ gap
                int gap = i - lastPos;
                if (gap > maxGap) {
                    maxGap = gap;
                }
            }
            lastPos = i;  // อัพเดทตำแหน่งสุดท้าย
        }
    }
    
    return maxGap;
}