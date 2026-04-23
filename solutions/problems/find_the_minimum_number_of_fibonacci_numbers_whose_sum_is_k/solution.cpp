class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        int result = 0;
        int remaining = k;
        
        while (remaining > 0) {
            // หา Fibonacci number ที่มากที่สุด <= remaining
            int a = 1, b = 1;
            while (b <= remaining) {
                int temp = a + b;
                a = b;
                b = temp;
            }
            // a คือ Fibonacci number ที่มากที่สุด <= remaining
            remaining -= a;
            result++;
        }
        
        return result;
    }
};