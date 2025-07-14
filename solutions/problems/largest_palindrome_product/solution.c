bool has_n_digit_factors(long long num, int n) {
    long long upper = pow(10, n) - 1;
    long long lower = pow(10, n - 1);
    
    for (long long i = upper; i >= lower; i--) {
        if (num % i == 0) {
            long long other = num / i;
            if (other >= lower && other <= upper) {
                return true;
            }
        }
        if (i * i < num) break;
    }
    return false;
}

int largestPalindrome(int n) {
    if (n == 1) return 9;
    
    long long upper = pow(10, n) - 1;
    long long lower = pow(10, n - 1);
    long long max_product = upper * upper;
    
    // หา palindrome ที่ใหญ่ที่สุดที่น้อยกว่าหรือเท่ากับ max_product
    long long first_half = max_product / pow(10, n);
    
    for (long long i = first_half; i >= lower; i--) {
        // สร้าง palindrome จาก i
        char s[20], rev[20];
        sprintf(s, "%lld", i);
        int len = strlen(s);
        
        // สร้าง reversed string
        for (int j = 0; j < len; j++) {
            rev[j] = s[len-1-j];
        }
        rev[len] = '\0';
        
        // รวม string เพื่อสร้าง palindrome
        char palindrome_str[40];
        strcpy(palindrome_str, s);
        strcat(palindrome_str, rev);
        
        long long palindrome = atoll(palindrome_str);
        if (palindrome > max_product) continue;
        
        // ตรวจสอบว่าสามารถแยกตัวประกอบได้หรือไม่
        if (has_n_digit_factors(palindrome, n)) {
            return (int)(palindrome % 1337);
        }
    }
    
    return 0;
}