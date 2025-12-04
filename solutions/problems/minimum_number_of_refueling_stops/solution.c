int minRefuelStops(int target, int startFuel, int** stations, int stationsSize, int* stationsColSize) {
    // กรณีพิเศษ: ไม่ต้องจอดก็ถึงแล้ว
    if (startFuel >= target) {
        return 0;
    }
    
    // สร้าง dp array ตำแหน่งที่ไปได้ไกลสุดด้วยการจอดเติม j ครั้ง
    long long* dp = (long long*)calloc(stationsSize + 1, sizeof(long long));
    
    // ไม่จอดเลย
    dp[0] = startFuel;
    
    // สำหรับแต่ละสถานี
    for (int i = 0; i < stationsSize; i++) {
        int position = stations[i][0];
        int fuel = stations[i][1];
        
        // ตรวจสอบจากหลังมาหน้า
        for (int j = i; j >= 0; j--) {
            // ถ้าไปถึงสถานีนี้ได้ด้วยการจอด j ครั้ง
            if (dp[j] >= position) {
                // อัพเดทการจอด j+1 ครั้ง
                if (dp[j] + fuel > dp[j + 1]) {
                    dp[j + 1] = dp[j] + fuel;
                }
            } else {
                break;
            }
        }
    }
    
    // หาคำตอบ
    int answer = -1;
    for (int i = 0; i <= stationsSize; i++) {
        if (dp[i] >= target) {
            answer = i;
            break;
        }
    }
    
    free(dp);
    return answer;
}