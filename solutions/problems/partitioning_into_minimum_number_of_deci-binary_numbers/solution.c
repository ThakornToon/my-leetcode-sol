int minPartitions(char* n) {
    int maxDigit = 0;
    int len = strlen(n);
    
    for (int i = 0; i < len; i++) {
        // แปลง char เป็น int (ASCII '0' = 48)
        int digit = n[i] - '0';
        
        // อัปเดตค่ามากที่สุด
        if (digit > maxDigit) {
            maxDigit = digit;
            
            // ถ้าเจอ 9 แล้ว ก็ไม่ต้องหาต่อ เพราะมากที่สุดแล้ว
            if (maxDigit == 9) {
                return 9;
            }
        }
    }
    
    return maxDigit;
}