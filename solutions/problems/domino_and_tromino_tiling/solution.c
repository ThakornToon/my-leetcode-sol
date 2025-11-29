int numTilings(int n) {
    if (n <= 2) return n;
    if (n == 3) return 5;
    
    const int MOD = 1e9 + 7;
    long long one = 1; 
    long long two = 2; 
    long long three = 5;
        
    for (int i = 4; i <= n; i++) {
        int four = (2 * three + one) % MOD;
        one = two;
        two = three;
        three = four;
    }
        
    return three;
}