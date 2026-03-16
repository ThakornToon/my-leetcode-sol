#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define NUM_KEYS 26

// ฟังก์ชันคำนวณระยะทางระหว่างสองตำแหน่ง
int distance(int from, int to) {
    if (from == -1) return 0;  // นิ้วเริ่มต้นที่ตำแหน่งใดก็ได้
    int x1 = from / 6;
    int y1 = from % 6;
    int x2 = to / 6;
    int y2 = to % 6;
    return abs(x1 - x2) + abs(y1 - y2);
}

int minimumDistance(char* word) {
    int n = strlen(word);
    
    // dp[i][j] = ระยะทางน้อยที่สุดเมื่อนิ้ว 1 อยู่ที่ i, นิ้ว 2 อยู่ที่ j
    int dp[NUM_KEYS][NUM_KEYS];
    
    // initialize
    for (int i = 0; i < NUM_KEYS; i++) {
        for (int j = 0; j < NUM_KEYS; j++) {
            dp[i][j] = INT_MAX / 2;
        }
    }
    
    // พิมพ์ตัวแรก
    int first = word[0] - 'A';
    for (int i = 0; i < NUM_KEYS; i++) {
        dp[first][i] = distance(-1, first);
        dp[i][first] = distance(-1, first);
    }
    
    // พิมพ์ตัวถัดไป
    for (int pos = 1; pos < n; pos++) {
        int curr = word[pos] - 'A';
        int new_dp[NUM_KEYS][NUM_KEYS];
        
        // initialize new_dp
        for (int i = 0; i < NUM_KEYS; i++) {
            for (int j = 0; j < NUM_KEYS; j++) {
                new_dp[i][j] = INT_MAX / 2;
            }
        }
        
        // คำนวณจาก dp เดิม
        for (int i = 0; i < NUM_KEYS; i++) {
            for (int j = 0; j < NUM_KEYS; j++) {
                if (dp[i][j] == INT_MAX / 2) continue;
                
                // ใช้นิ้ว 1 พิมพ์ curr
                new_dp[curr][j] = MIN(new_dp[curr][j], 
                                     dp[i][j] + distance(i, curr));
                
                // ใช้นิ้ว 2 พิมพ์ curr
                new_dp[i][curr] = MIN(new_dp[i][curr], 
                                     dp[i][j] + distance(j, curr));
            }
        }
        
        // copy กลับ
        for (int i = 0; i < NUM_KEYS; i++) {
            for (int j = 0; j < NUM_KEYS; j++) {
                dp[i][j] = new_dp[i][j];
            }
        }
    }
    
    // หาค่าน้อยที่สุด
    int result = INT_MAX;
    for (int i = 0; i < NUM_KEYS; i++) {
        for (int j = 0; j < NUM_KEYS; j++) {
            result = MIN(result, dp[i][j]);
        }
    }
    
    return result;
}