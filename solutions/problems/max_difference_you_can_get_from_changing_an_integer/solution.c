int maxDiff(int num) {
    char s[12];
    sprintf(s, "%d", num);
    int n = strlen(s);
    
    // หาค่าสูงสุด: เปลี่ยน digit แรกที่ไม่ใช่ 9 เป็น 9
    char maxStr[12];
    strcpy(maxStr, s);
    for (int i = 0; i < n; i++) {
        if (maxStr[i] != '9') {
            char target = maxStr[i];
            for (int j = 0; j < n; j++) {
                if (maxStr[j] == target) {
                    maxStr[j] = '9';
                }
            }
            break;
        }
    }
    
    // หาค่าต่ำสุด
    char minStr[12];
    strcpy(minStr, s);
    
    // ถ้าหลักแรกไม่ใช่ '1' ให้เปลี่ยนหลักแรกเป็น '1'
    if (minStr[0] != '1') {
        char target = minStr[0];
        for (int i = 0; i < n; i++) {
            if (minStr[i] == target) {
                minStr[i] = '1';
            }
        }
    } else {
        // หลักแรกเป็น '1' แล้ว: หา digit (ไม่ใช่ '0' และไม่ใช่ '1')
        // ที่จะเปลี่ยนเป็น '0' (เปลี่ยนเฉพาะ digit ที่ไม่ใช่หลักแรก)
        for (int i = 1; i < n; i++) {
            if (minStr[i] != '0' && minStr[i] != '1') {
                char target = minStr[i];
                for (int j = 1; j < n; j++) {  // เริ่มจาก j=1 ป้องกันเปลี่ยนหลักแรก
                    if (minStr[j] == target) {
                        minStr[j] = '0';
                    }
                }
                break;
            }
        }
    }
    
    int maxVal = atoi(maxStr);
    int minVal = atoi(minStr);
    
    return maxVal - minVal;
}