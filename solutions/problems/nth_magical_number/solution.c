int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int nthMagicalNumber(int n, int a, int b) {
    const int MOD = 1000000007;
    
    // หา LCM
    long long lcm = (long long)a * b / gcd(a, b);
    
    long long low = a < b ? a : b;
    long long high = (long long)n * low;
    
    while (low < high) {
        long long mid = low + (high - low) / 2;
        
        // count = floor(mid/a) + floor(mid/b) - floor(mid/lcm)
        long long count = mid / a + mid / b - mid / lcm;
        
        if (count < n) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    
    return low % MOD;
}