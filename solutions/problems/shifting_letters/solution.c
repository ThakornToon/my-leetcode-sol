char* shiftingLetters(char* s, int* shifts, int shiftsSize) {
    // prefix sum จากหลังมาหน้า
    long long prefixSum = 0;
        
    // Shift แต่ละตัวอักษร
    for (int i = shiftsSize - 1; i >= 0; i--) {
        prefixSum += shifts[i];
        prefixSum %= 26;  // mod 26 เพราะเกิน 26 จะวนกลับ
        s[i] = 'a' + (s[i] - 'a' + prefixSum) % 26;
    }
        
    return s;
}