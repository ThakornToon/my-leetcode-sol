// ฟังก์ชันคำนวณ waviness ของตัวเลข 1 ตัว
int calculateWaviness(int num) {
    if (num < 100) return 0; // ตัวเลขที่มีน้อยกว่า 3 หลัก
    
    // แปลงตัวเลขเป็น string เพื่อเข้าถึงแต่ละหลัก
    char str[7];
    sprintf(str, "%d", num);
    int len = strlen(str);
    
    int waviness = 0;
    
    // ตรวจสอบแต่ละหลัก (ยกเว้นหลักแรกและหลักสุดท้าย)
    for (int i = 1; i < len - 1; i++) {
        int prev = str[i-1] - '0';
        int curr = str[i] - '0';
        int next = str[i+1] - '0';
        
        // ตรวจสอบว่าเป็น peak หรือ valley
        if (curr > prev && curr > next) {
            waviness++; // peak
        } else if (curr < prev && curr < next) {
            waviness++; // valley
        }
    }
    
    return waviness;
}

int totalWaviness(int num1, int num2) {
    int total = 0;
    
    // วนลูปทุกตัวเลขในช่วง [num1, num2]
    for (int num = num1; num <= num2; num++) {
        total += calculateWaviness(num);
    }
    
    return total;
}