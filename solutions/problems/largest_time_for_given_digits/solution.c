char* largestTimeFromDigits(int* arr, int arrSize) {
    char* result = (char*)malloc(6 * sizeof(char));
    strcpy(result, "");
    
    // เรียงจากมากไปน้อยก่อน
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    // พยายามหาชั่วโมงให้มากที่สุด
    int h1 = -1, h2 = -1, m1 = -1, m2 = -1;
    
    // หา h1 (หลักสิบของชั่วโมง) ที่เป็นไปได้
    for (int i = 0; i < 4; i++) {
        if (arr[i] <= 2) {
            h1 = arr[i];
            // ลบตัวที่ใช้แล้ว
            int temp = arr[i];
            arr[i] = -1;
            
            // หา h2 ที่เป็นไปได้
            for (int j = 0; j < 4; j++) {
                if (arr[j] != -1) {
                    int possibleH2 = (h1 == 2) ? (arr[j] <= 3) : 1;
                    if (possibleH2) {
                        h2 = arr[j];
                        arr[j] = -1;
                        
                        // หา m1, m2 ที่เหลือ
                        int remaining[2], idx = 0;
                        for (int k = 0; k < 4; k++) {
                            if (arr[k] != -1) {
                                remaining[idx++] = arr[k];
                            }
                        }
                        
                        // พยายามทำให้นาทีมากที่สุด
                        if (remaining[0] <= 5 && remaining[1] <= 5) {
                            // เรียงจากมากไปน้อย
                            if (remaining[0] < remaining[1]) {
                                int temp = remaining[0];
                                remaining[0] = remaining[1];
                                remaining[1] = temp;
                            }
                            m1 = remaining[0];
                            m2 = remaining[1];
                        } else if (remaining[0] <= 5) {
                            m1 = remaining[0];
                            m2 = remaining[1];
                        } else if (remaining[1] <= 5) {
                            m1 = remaining[1];
                            m2 = remaining[0];
                        }
                        
                        // ถ้าพบ valid time ให้หยุด
                        if (m1 != -1) {
                            sprintf(result, "%d%d:%d%d", h1, h2, m1, m2);
                            return result;
                        }
                        
                        // ถ้ายังไม่เจอ กลับไปหา h2 อื่น
                        arr[j] = h2;
                        h2 = -1;
                    }
                }
            }
            
            // ถ้ายังไม่เจอ กลับไปหา h1 อื่น
            arr[i] = temp;
            h1 = -1;
        }
    }
    
    return result;
}