#define MAX_SEATS 10

// ฟังก์ชันเปรียบเทียบสำหรับ qsort (รับ pointer to pointer)
int compare(const void* a, const void* b) {
    int* seatA = *(int**)a;
    int* seatB = *(int**)b;
    
    // เรียงตามแถว แล้วตามด้วยคอลัมน์
    if (seatA[0] != seatB[0]) {
        return seatA[0] - seatB[0];
    }
    return seatA[1] - seatB[1];
}

int maxNumberOfFamilies(int n, int** reservedSeats, int reservedSeatsSize, int* reservedSeatsColSize) {
    if (reservedSeatsSize == 0) {
        return n * 2;
    }
    
    // sort reserved seats (จองพื้นที่ pointer size)
    qsort(reservedSeats, reservedSeatsSize, sizeof(int*), compare);
    
    int total = 0;
    int i = 0;
    int lastProcessedRow = 0;
    
    while (i < reservedSeatsSize) {
        int currentRow = reservedSeats[i][0];
        
        // นับแถวที่ไม่มี reservation ก่อนถึงแถวนี้
        // แถวที่ 1 ถึง currentRow-1 ที่ไม่มี reservation
        total += (currentRow - lastProcessedRow - 1) * 2;
        
        // เก็บที่นั่งที่ถูกจองในแถวนี้
        int reserved[MAX_SEATS + 1] = {0};  // index 1-10
        
        while (i < reservedSeatsSize && reservedSeats[i][0] == currentRow) {
            reserved[reservedSeats[i][1]] = 1;
            i++;
        }
        
        // ตรวจสอบรูปแบบ
        int left = !reserved[2] && !reserved[3] && !reserved[4] && !reserved[5];
        int middle = !reserved[4] && !reserved[5] && !reserved[6] && !reserved[7];
        int right = !reserved[6] && !reserved[7] && !reserved[8] && !reserved[9];
        
        if (left && right) {
            total += 2;
        } else if (left || middle || right) {
            total += 1;
        }
        
        lastProcessedRow = currentRow;
    }
    
    // แถวหลังแถวสุดท้ายที่มี reservation
    total += (n - lastProcessedRow) * 2;
    
    return total;
}