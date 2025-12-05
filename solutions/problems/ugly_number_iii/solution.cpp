class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b != 0) {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    
    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }
    
    long long countUgly(long long mid, long long a, long long b, long long c) {
        long long lab = lcm(a, b);
        long long lbc = lcm(b, c);
        long long lac = lcm(a, c);
        long long labc = lcm(lab, c);
        
        return mid/a + mid/b + mid/c
               - mid/lab - mid/lbc - mid/lac
               + mid/labc;
    }
    
    int nthUglyNumber(int n, int a, int b, int c) {
        long long left = 1;
        long long min_val = min({(long long)a, (long long)b, (long long)c});
        long long right = (long long)n * min_val;
        
        while (left < right) {
            long long mid = left + (right - left) / 2;
            
            if (countUgly(mid, a, b, c) >= n) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return (int)left;
    }
};