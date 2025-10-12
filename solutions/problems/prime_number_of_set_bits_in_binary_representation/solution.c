int countPrimeSetBits(int left, int right) {
    // จำนวนเฉพาะที่ ≤ 20
    bool isPrime[21] = {false, false, true, true, false, true, 
                       false, true, false, false, false, true,
                       false, true, false, false, false, true,
                       false, true, false};
    
    int count = 0;
    for (int i = left; i <= right; i++) {
        int num = i;
        int bits = 0;
        
        // นับจำนวน bit 1
        while (num > 0) {
            bits += num & 1;
            num >>= 1;
        }
        
        if (isPrime[bits]) {
            count++;
        }
    }
    return count;
}