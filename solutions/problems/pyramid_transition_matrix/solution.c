#define MAX_N 10

// ใช้ 3D array สำหรับเก็บ rules: rules[left][right][top]
bool rules[7][7][7] = {false};

bool canBuild(char* current) {
    int len = strlen(current);
    
    // Base case: ถึงยอดพีระมิดแล้ว
    if (len == 1) {
        return true;
    }
    
    // ฟังก์ชันสร้างแถวถัดไป
    bool buildNext(int idx, char* next) {
        if (idx == len - 1) {
            // เรียก recursive สำหรับแถวถัดไป
            return canBuild(next);
        }
        
        char left = current[idx];
        char right = current[idx + 1];
        
        // ลองทุกตัวอักษรที่เป็นไปได้ (A-G)
        for (char top = 'A'; top <= 'G'; top++) {
            if (rules[left - 'A'][right - 'A'][top - 'A']) {
                char new_next[MAX_N];
                strcpy(new_next, next);
                int new_len = strlen(new_next);
                new_next[new_len] = top;
                new_next[new_len + 1] = '\0';
                
                if (buildNext(idx + 1, new_next)) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    char next_level[MAX_N] = "";
    return buildNext(0, next_level);
}

bool pyramidTransition(char* bottom, char** allowed, int allowedSize) {
    // รีเซ็ต rules
    memset(rules, 0, sizeof(rules));
    
    // เติมข้อมูล rules ลงใน 3D array
    for (int i = 0; i < allowedSize; i++) {
        int left = allowed[i][0] - 'A';
        int right = allowed[i][1] - 'A';
        int top = allowed[i][2] - 'A';
        rules[left][right][top] = true;
    }
    
    return canBuild(bottom);
}
