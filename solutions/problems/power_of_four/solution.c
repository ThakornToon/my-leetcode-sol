bool isPowerOfFour(int n) {
    if (n <= 0) return false;
    double log = log2(n) / 2;
    return log == (int)log;
}