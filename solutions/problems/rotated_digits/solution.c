// Valid digits and their rotations
int valid_digits[] = {0, 1, 2, 5, 6, 8, 9};
int rotation[] =     {0, 1, 5, 2, 9, 8, 6};
int count = 0;

void generateNumbers(long long current, int hasGoodDigit, int max_n) {
    if (current > max_n) return;
    
    // ถ้ามีอย่างน้อยหนึ่ง digit ที่หมุนแล้วเปลี่ยนค่า (2,5,6,9)
    if (hasGoodDigit && current <= max_n && current > 0) {
        count++;
    }
    
    // สร้างตัวเลขต่อไปโดยเพิ่ม digit
    for (int i = 0; i < 7; i++) {
        int digit = valid_digits[i];
        
        // หลีกเลี่ยง leading zero
        if (current == 0 && digit == 0) continue;
        
        long long next = current * 10 + digit;
        int newHasGoodDigit = hasGoodDigit || (digit == 2 || digit == 5 || digit == 6 || digit == 9);
        
        generateNumbers(next, newHasGoodDigit, max_n);
    }
}

int rotatedDigits(int n) {
    count = 0;
    generateNumbers(0, 0, n);
    return count;
}