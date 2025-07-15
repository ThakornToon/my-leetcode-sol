#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct {
    char ch;
    int* positions;
    int count;
} CharPositions;

int findRotateSteps(char* ring, char* key) {
    int ring_len = strlen(ring);
    int key_len = strlen(key);
    
    // สร้างตารางเก็บตำแหน่งของแต่ละอักษรใน ring
    CharPositions char_pos[26] = {0};
    for (int i = 0; i < ring_len; i++) {
        int idx = ring[i] - 'a';
        if (char_pos[idx].count == 0) {
            char_pos[idx].positions = (int*)malloc(ring_len * sizeof(int));
        }
        char_pos[idx].positions[char_pos[idx].count++] = i;
    }
    
    // สร้างตาราง DP : dp[i][j] รำนวนขั้นต่ำที่ต้องใช้เพื่อพิมพ์ i + 1 ตัวอักษรแรกของ key เมื่ออักษรปัจจุบันของ ring อยู่ที่ตำแหน่ง j
    int** dp = (int**)malloc(key_len * sizeof(int*));
    for (int i = 0; i < key_len; i++) {
        dp[i] = (int*)malloc(ring_len * sizeof(int));
        for (int j = 0; j < ring_len; j++) {
            dp[i][j] = INT_MAX;
        }
    }
    
    // เริ่มต้นสำหรับอักษรแรกใน key
    int first_char = key[0] - 'a';
    for (int i = 0; i < char_pos[first_char].count; i++) {
        int pos = char_pos[first_char].positions[i];
        int distance = MIN(pos, ring_len - pos); // จะไปทวนเข็มหรือตามเข็ม
        dp[0][pos] = distance + 1;
    }
    
    // คำนวณ DP ตัวอักษรปัจจุบันโดยเดินทางต่อมาจากตัวอักษรก่อนหน้าไป
    for (int i = 1; i < key_len; i++) {
        int current_char = key[i] - 'a';
        int prev_char = key[i-1] - 'a';
        
        for (int j = 0; j < char_pos[current_char].count; j++) {
            int current_pos = char_pos[current_char].positions[j];
            
            for (int k = 0; k < char_pos[prev_char].count; k++) {
                int prev_pos = char_pos[prev_char].positions[k];
                int distance = abs(current_pos - prev_pos); 
                distance = MIN(distance, ring_len - distance);
                
                if (dp[i-1][prev_pos] + distance + 1 < dp[i][current_pos]) {
                    dp[i][current_pos] = dp[i-1][prev_pos] + distance + 1;
                }
            }
        }
    }
    
    // หาค่าน้อยที่สุดในแถวสุดท้ายของ DP
    int min_steps = INT_MAX;
    int last_char = key[key_len-1] - 'a';
    for (int i = 0; i < char_pos[last_char].count; i++) {
        int pos = char_pos[last_char].positions[i];
        if (dp[key_len-1][pos] < min_steps) {
            min_steps = dp[key_len-1][pos];
        }
    }
    
    // คืนหน่วยความจำ
    for (int i = 0; i < 26; i++) {
        if (char_pos[i].positions) {
            free(char_pos[i].positions);
        }
    }
    for (int i = 0; i < key_len; i++) {
        free(dp[i]);
    }
    free(dp);
    
    return min_steps;
}