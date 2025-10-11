int monotoneIncreasingDigits(int n) {
    if (n < 10) return n;
    
    int digits[10];
    int len = 0;
    int temp = n;
    
    // ดึงทีละหลักจากหลังมาหน้า
    while (temp > 0) {
        digits[len++] = temp % 10;
        temp /= 10;
    }
    
    // กลับให้เรียงตามเดิม
    for (int i = 0; i < len / 2; i++) {
        int temp = digits[i];
        digits[i] = digits[len - 1 - i];
        digits[len - 1 - i] = temp;
    }
    
    int marker = len;
    
    for (int i = len - 1; i > 0; i--) {
        if (digits[i] < digits[i - 1]) {
            marker = i;
            digits[i - 1]--;
        }
    }
    
    for (int i = marker; i < len; i++) {
        digits[i] = 9;
    }
    
    int result = 0;
    for (int i = 0; i < len; i++) {
        result = result * 10 + digits[i];
    }
    
    return result;
}