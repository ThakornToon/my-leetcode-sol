char* longestDiverseString(int a, int b, int c) {
    // จองพื้นที่สำหรับผลลัพธ์ (มากสุด a+b+c+1)
    int total = a + b + c;
    char* result = (char*)malloc((total + 1) * sizeof(char));
    int idx = 0;
    
    while (a > 0 || b > 0 || c > 0) {
        // ตรวจสอบว่าควรเลือกตัวอักษรไหน
        int chooseA = 0, chooseB = 0, chooseC = 0;
        
        // ถ้า a มีมากที่สุด และไม่ทำให้เกิด 3 ตัวซ้ำ
        if (a >= b && a >= c) {
            // ตรวจสอบ 2 ตัวสุดท้าย
            if (idx >= 2 && result[idx - 1] == 'a' && result[idx - 2] == 'a') {
                // ต้องเลือก b หรือ c แทน
                if (b >= c && b > 0) {
                    chooseB = 1;
                } else if (c > 0) {
                    chooseC = 1;
                } else {
                    break;
                }
            } else if (a > 0) {
                chooseA = 1;
            }
        }
        // ถ้า b มีมากที่สุด
        else if (b >= a && b >= c) {
            if (idx >= 2 && result[idx - 1] == 'b' && result[idx - 2] == 'b') {
                if (a >= c && a > 0) {
                    chooseA = 1;
                } else if (c > 0) {
                    chooseC = 1;
                } else {
                    break;
                }
            } else if (b > 0) {
                chooseB = 1;
            }
        }
        // ถ้า c มีมากที่สุด
        else {
            if (idx >= 2 && result[idx - 1] == 'c' && result[idx - 2] == 'c') {
                if (a >= b && a > 0) {
                    chooseA = 1;
                } else if (b > 0) {
                    chooseB = 1;
                } else {
                    break;
                }
            } else if (c > 0) {
                chooseC = 1;
            }
        }
        
        // เพิ่มตัวอักษรที่เลือก
        if (chooseA) {
            result[idx++] = 'a';
            a--;
        } else if (chooseB) {
            result[idx++] = 'b';
            b--;
        } else if (chooseC) {
            result[idx++] = 'c';
            c--;
        } else {
            break;
        }
    }
    
    result[idx] = '\0';
    return result;

}