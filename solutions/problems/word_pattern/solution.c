void cleanup(char* value[26]) {
    for (int i = 0; i < 26; i++) {
        if (value[i]) {
            free(value[i]);
            value[i] = NULL;
        }
    }
}

bool wordPattern(char* pattern, char* s) {
    bool key[26] = {false};
    char* value[26] = {NULL};
    int pattern_len = strlen(pattern);
    int s_len = strlen(s);
    int curr = 0, i = 0;
   
    while (i < s_len && curr < pattern_len) {
        // หาตำแหน่งสิ้นสุดคำปัจจุบัน
        int j = i;
        while (j < s_len && s[j] != ' ') j++;
        
        int k = pattern[curr] - 'a';
        if (key[k]) {
            // ตรวจสอบว่าคำตรงกับที่เคยจับคู่ไว้หรือไม่
            char* word = value[k];
            int check = 0;
            while (i < j) {
                if (word[check] != s[i]) {
                    cleanup(value);
                    return false;
                }
                i++;
                check++;
            }
            if (word[check] != '\0') {
                cleanup(value);
                return false;
            }
        } else {
            // ตรวจสอบว่าคำนี้เคยจับคู่กับตัวอักษรอื่นหรือไม่
            for (int m = 0; m < 26; m++) {
                if (m != k && value[m] && strncmp(value[m], s + i, j - i) == 0) {
                    cleanup(value);
                    return false;
                }
            }
            
            // จับคู่คำใหม่
            key[k] = true;
            value[k] = strndup(s + i, j - i);
            
        }
        
        i = j + 1; // ข้ามช่องว่าง
        curr++;
    }

    bool result = (curr == pattern_len && i >= s_len);
    cleanup(value);
    return result;
}