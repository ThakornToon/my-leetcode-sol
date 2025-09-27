int findIntegers(int n) {
    if (n < 2) return n + 1;
    
    // สร้าง Fibonacci sequence
    int fib[32];
    fib[0] = 1;  // f(0) = 1 (จำนวนยาว 0 บิต: "0")
    fib[1] = 2;  // f(1) = 2 (จำนวนยาว 1 บิต: "0", "1")
    
    for (int i = 2; i < 32; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    
    // หาความยาวบิตสูงสุด
    int len = 0;
    int temp = n;
    while (temp > 0) {
        len++;
        temp >>= 1;
    }
    
    int result = 0;
    int prev_bit = 0;
    
    for (int i = len - 1; i >= 0; i--) {
        int bit = (n >> i) & 1;
        
        if (bit == 1) {
            // นับจำนวนที่บิตนี้เป็น 0
            result += fib[i];
            
            if (prev_bit == 1) {
                // พบ 1 ต่อเนื่องสองตัว → หยุดนับ
                return result;
            }
        }
        prev_bit = bit;
    }
    
    // บวก 1 สำหรับตัว n เอง
    return result + 1;
}