#define MY_MAX(a, b) ((a) > (b) ? (a) : (b))

int maxStudents(char** seats, int seatsSize, int* seatsColSize) {
    int m = seatsSize;
    int n = seatsColSize[0];
    int maxMask = 1 << n;
    
    // สร้าง mask สำหรับที่นั่งเสีย
    int* broken = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        int mask = 0;
        for (int j = 0; j < n; j++) {
            if (seats[i][j] == '#') {
                mask |= (1 << j);
            }
        }
        broken[i] = mask;
    }
    
    // dp[row][mask] = max students จากแถว row ถึงแถวสุดท้าย
    int** dp = (int**)malloc((m + 1) * sizeof(int*));
    for (int i = 0; i <= m; i++) {
        dp[i] = (int*)malloc(maxMask * sizeof(int));
        for (int j = 0; j < maxMask; j++) {
            dp[i][j] = -1;
        }
    }
    
    // Base case: แถวสุดท้าย (row = m) มี 0 คน
    for (int mask = 0; mask < maxMask; mask++) {
        dp[m][mask] = -1;
    }
    
    // วนจากแถวล่างขึ้นบน
    for (int i = m - 1; i >= 0; i--) {
        for (int currMask = 0; currMask < maxMask; currMask++) {
            // ตรวจสอบว่าที่นั่งเสีย
            if ((currMask & broken[i]) != 0) continue;
            
            // ตรวจสอบแนวนอน
            if ((currMask & (currMask << 1)) != 0) continue;
            
            // ลองทุก mask ของแถวข้างล่าง
            for (int prevMask = 0; prevMask < maxMask; prevMask++) {
                if (dp[i + 1][prevMask] == -1) continue;
                
                // ตรวจสอบแนวทแยงกับแถวล่าง (bottom)
        
                // ซ้ายล่าง: currMask มี bit ที่ j และ nextMask มี bit ที่ j-1
                if ((currMask & (prevMask << 1)) != 0) continue;
                // ขวาล่าง: currMask มี bit ที่ j และ nextMask มี bit ที่ j+1
                if ((currMask & (prevMask >> 1)) != 0) continue;
                
                int cnt = __builtin_popcount(currMask);
                dp[i][currMask] = MY_MAX(dp[i][currMask], cnt + dp[i + 1][prevMask]);
            }
            
            // กรณี dp[i][currMask] ยังเป็น -1 ให้ตั้งเป็น 0
            if (dp[i][currMask] == -1) {
                dp[i][currMask] = __builtin_popcount(currMask);
            }
        }
    }
    
    // หาค่าสูงสุดในแถวแรก
    int result = 0;
    for (int mask = 0; mask < maxMask; mask++) {
        result = MY_MAX(result, dp[0][mask]);
    }
    
    // คืนหน่วยความจำ
    for (int i = 0; i <= m; i++) {
        free(dp[i]);
    }
    free(dp);
    free(broken);
    
    return result;
}