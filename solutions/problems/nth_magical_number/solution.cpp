class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        const int MOD = 1e9 + 7;
        
        long long lcm = (long long)a * b / __gcd(a, b);
        long long low = min(a, b);
        long long high = (long long)n * min(a, b);
        
        while (low < high) {
            long long mid = low + (high - low) / 2;
            
            // นับจำนวนมหัศจรรย์ ≤ mid
            long long count = (mid / a) + (mid / b) - (mid / lcm);
            
            if (count < n) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        
        return low % MOD;
    }
};