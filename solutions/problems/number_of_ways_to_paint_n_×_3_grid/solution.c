int numOfWays(int n) {
    long long mod = 1000000007;
    
    if (n == 1) return 12;
    
    long long dpA = 6;  // Type ABA
    long long dpB = 6;  // Type ABC
    
    for (int i = 2; i <= n; i++) {
        long long newA = (3 * dpA + 2 * dpB) % mod;
        long long newB = (2 * dpA + 2 * dpB) % mod;
        dpA = newA;
        dpB = newB;
    }
    
    return (int)((dpA + dpB) % mod);
}