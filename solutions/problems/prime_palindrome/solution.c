// ตรวจสอบว่าเป็น prime หรือไม่
bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    
    int limit = sqrt(n);
    for (int i = 3; i <= limit; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

// ตรวจสอบว่าเป็น palindrome หรือไม่
bool isPalindrome(int n) {
    if (n < 0) return false;
    
    int reversed = 0;
    int original = n;
    
    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    
    return original == reversed;
}

int primePalindrome(int n) {
    if (n <= 2) return 2;
    if (n <= 3) return 3;
    if (n <= 5) return 5;
    if (n <= 7) return 7;
    if (n <= 11) return 11;
    
    // เริ่มจาก N
    for (int i = n; i <= INT_MAX; i++) {
        // Optimization: ข้ามเลขที่มีจำนวนหลักเป็นคู่ (ยกเว้น 11)
        if (i > 11 && i < 100) i = 101;          // ข้าม 2 หลัก
        else if (i > 1000 && i < 10000) i = 10001; // ข้าม 4 หลัก  
        else if (i > 100000 && i < 1000000) i = 1000001; // ข้าม 6 หลัก
        else if (i > 10000000 && i < 100000000) i = 100000001; // ข้าม 8 หลัก

        if (isPalindrome(i) && isPrime(i)) {
            return i;
        }
    }
    
    return -1; // เกิน i32
}