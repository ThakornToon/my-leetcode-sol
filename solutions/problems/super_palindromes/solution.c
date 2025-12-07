long long super_palindromes[] = {
    1, 2, 3, 11, 22, 101, 111, 121, 202, 212, 
    1001, 1111, 2002, 10001, 10101, 10201, 11011, 11111, 11211, 20002, 20102, 
    100001, 101101, 110011, 111111, 200002, 1000001, 1001001, 1002001, 1010101, 
    1011101, 1012101, 1100011, 1101011, 1102011, 1110111, 1111111, 2000002, 2001002, 
    10000001, 10011001, 10100101, 10111101, 11000011, 11011011, 11100111, 11111111, 
    20000002, 100000001, 100010001, 100020001, 100101001, 100111001, 100121001, 
    101000101, 101010101, 101020101, 101101101, 101111101, 110000011, 110010011, 
    110020011, 110101011, 110111011, 111000111, 111010111, 111101111, 111111111, 
    200000002, 200010002
};

int super_palindromes_count = sizeof(super_palindromes) / sizeof(super_palindromes[0]);

bool is_palindrome(long long x) {
    if (x < 0) return false;
    long long reversed = 0;
    long long original = x;
    
    while (x > 0) {
        reversed = reversed * 10 + (x % 10);
        x /= 10;
    }
    
    return reversed == original;
}

int superpalindromesInRange(char* left, char* right) {
    long long L = atoll(left);
    long long R = atoll(right);
    int count = 0;
    
    for (int i = 0; i < super_palindromes_count; i++) {
        long long p = super_palindromes[i];
        long long x = p * p;
        
        if (x > R) break;  // เพราะ list เรียงจากน้อยไปมาก
        
        if (x >= L) {
            // ตรวจสอบอีกครั้งว่าเป็น palindrome (เพื่อความชัวร์)
            if (is_palindrome(x)) {
                count++;
            }
        }
    }
    
    return count;
}