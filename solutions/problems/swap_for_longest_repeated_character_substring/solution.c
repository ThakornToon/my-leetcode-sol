int max(int a, int b) {
    return a > b ? a : b;
}

int maxRepOpt1(char* text) {
    int n = strlen(text);
    if (n == 0) return 0;
    
    // นับจำนวนตัวอักษรทั้งหมด
    int count[26] = {0};
    for (int i = 0; i < n; i++) {
        count[text[i] - 'a']++;
    }
    
    int maxLen = 0;
    
    // สำหรับแต่ละตัวอักษรที่เป็นไปได้
    for (char c = 'a'; c <= 'z'; c++) {
        int total = count[c - 'a'];
        if (total == 0) continue;
        
        // Sliding window
        int left = 0, right = 0;
        int different = 0;  // จำนวนตัวอักษรที่ไม่ใช่ c ใน window
        
        while (right < n) {
            if (text[right] != c) {
                different++;
            }
            right++;
            
            // ถ้ามีตัวอักษรที่ไม่ใช่ c มากกว่า 1 ตัว
            while (different > 1) {
                if (text[left] != c) {
                    different--;
                }
                left++;
            }
            
            // ความยาวของ window
            int windowLen = right - left;
            
            // ตรวจสอบว่าสามารถสลับตัวอักษรได้หรือไม่
            if (windowLen <= total) {
                if (windowLen > maxLen) {
                    maxLen = windowLen;
                }
            } else {
                if (windowLen - 1 > maxLen) {
                    maxLen = windowLen - 1;
                }
            }
        }
    }
    
    return maxLen;
}