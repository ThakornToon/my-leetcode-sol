#define min(a, b) ((a) < (b) ? (a) : (b))

int balancedString(char* s) {
    int n = strlen(s);
    int k = n / 4;  // จำนวนที่ต้องการของแต่ละอักขระ
    
    // 0:Q, 1:W, 2:E, 3:R
    int count[4] = {0};
    
    // นับความถี่
    for (int i = 0; i < n; i++) {
        switch(s[i]) {
            case 'Q': count[0]++; break;
            case 'W': count[1]++; break;
            case 'E': count[2]++; break;
            case 'R': count[3]++; break;
        }
    }
    
    // ตรวจสอบว่าสมดุลอยู่แล้วหรือไม่
    if (count[0] == k && count[1] == k && count[2] == k && count[3] == k) {
        return 0;
    }
    
    int left = 0;
    int result = INT_MAX;
    int window[4] = {0};
    
    for (int right = 0; right < n; right++) {
        // เพิ่มอักขระทางขวา
        switch(s[right]) {
            case 'Q': window[0]++; break;
            case 'W': window[1]++; break;
            case 'E': window[2]++; break;
            case 'R': window[3]++; break;
        }
        
        // ลดหน้าต่างจากซ้ายถ้าเป็นไปได้
        while (left <= right) {
            // ตรวจสอบว่าการแทนที่หน้าต่างนี้จะทำให้สมดุลหรือไม่
            int valid = 1;
            for (int i = 0; i < 4; i++) {
                if (count[i] - window[i] > k) {
                    valid = 0;
                    break;
                }
            }
            
            if (valid) {
                // เทียบกับหน้าต่างปัจจุบัน
                result = min(result, right - left + 1);

                // ลบอักขระซ้ายออกจากหน้าต่าง(ลองลดขนาด)
                switch(s[left]) {
                    case 'Q': window[0]--; break;
                    case 'W': window[1]--; break;
                    case 'E': window[2]--; break;
                    case 'R': window[3]--; break;
                }
                left++;
            } else {
                // ลดขนาดไม่ได้อีกแล้ว
                break;
            }
        }
    }
    
    return result;
}