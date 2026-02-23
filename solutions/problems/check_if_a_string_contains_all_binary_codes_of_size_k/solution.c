bool hasAllCodes(char* s, int k) {
    int n = strlen(s);
    
    if (n < (1 << k) + k - 1) {
        return false;
    }

    int totalCodes = 1 << k;
    bool* seen = (bool*)calloc(totalCodes, sizeof(bool));
    
    for (int i = 0; i <= n - k; i++) {
        // แปลง substring เป็น int
        int val = 0;
        for (int j = 0; j < k; j++) {
            val = (val << 1) | (s[i + j] - '0');
        }
        seen[val] = true;
    }
    
    // ตรวจสอบว่าครบทุกแบบหรือไม่
    for (int i = 0; i < totalCodes; i++) {
        if (!seen[i]) {
            free(seen);
            return false;
        }
    }
    
    free(seen);
    return true;

}