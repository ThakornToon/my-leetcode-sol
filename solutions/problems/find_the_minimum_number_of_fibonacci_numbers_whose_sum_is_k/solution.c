int findMinFibonacciNumbers(int k) {
    if (k == 0) return 0;

    // หา Fibonacci number ที่มากที่สุด <= k
    int a = 1, b = 1;
    while (b <= k) {
        int temp = a + b;
        a = b;
        b = temp;
    }
    // b > k, a คือ Fibonacci number ที่มากที่สุด <= k
    
    return 1 + findMinFibonacciNumbers(k - a);
}