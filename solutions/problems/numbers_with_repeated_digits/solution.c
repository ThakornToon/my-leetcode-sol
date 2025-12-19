// คำนวณ A(n, k) = n!/(n-k)! = n × (n-1) × ... × (n-k+1)
int permutation(int n, int k) {
    if (k <= 0) return 1;
    int result = 1;
    for (int i = 0; i < k; i++) {
        result *= (n - i);
    }
    return result;
}

int numDupDigitsAtMostN(int n) {
    // แปลง n เป็น array ของตัวเลข
    int digits[10];
    int len = 0;
    int temp = n;
    
    while (temp > 0) {
        digits[len++] = temp % 10;
        temp /= 10;
    }
    
    // reverse array ให้เป็นลำดับปกติ
    for (int i = 0; i < len/2; i++) {
        int t = digits[i];
        digits[i] = digits[len-1-i];
        digits[len-1-i] = t;
    }
    
    int count = 0;
    int used[10] = {0};
    
    // 1. นับจำนวนที่มีหลักน้อยกว่า len
    for (int i = 1; i < len; i++) {
        count += 9 * permutation(9, i - 1);
    }
    
    // 2. นับจำนวนที่มี len หลัก และ ≤ n
    for (int i = 0; i < len; i++) {
        int start = (i == 0) ? 1 : 0;
        
        for (int d = start; d < digits[i]; d++) {
            if (!used[d]) {
                count += permutation(9 - i, len - i - 1);
            }
        }
        
        // ถ้าตัวเลขนี้ใช้ไปแล้ว หยุด
        if (used[digits[i]]) {
            return n - count;
        }
        used[digits[i]] = 1;
    }
    
    // เพิ่มตัว n เองถ้าไม่มีตัวเลขซ้ำ
    count++;
    
    return n - count;
}