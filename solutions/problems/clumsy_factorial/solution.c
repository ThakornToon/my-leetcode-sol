int clumsy(int n) {
if (n <= 2) return n;
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 6;
    if (n == 4) return 7;
    
    int result = n * (n - 1) / (n - 2) + (n - 3);
    n -= 4;
    
    while (n >= 4) {
        result -= (n * (n - 1) / (n - 2) - (n - 3));
        n -= 4;
    }
    
    // Handle remaining terms
    if (n == 0) return result;
    if (n == 1) return result - 1;
    if (n == 2) return result - 2;
    if (n == 3) return result - 6;
    
    return result;

}