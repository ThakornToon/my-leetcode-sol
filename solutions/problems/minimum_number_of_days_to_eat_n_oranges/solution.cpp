class Solution {
private:
    unordered_map<int, int> memo;
public:
    int minDays(int n) {
        if (n <= 1) return n;
        
        if (memo.count(n)) return memo[n];
        
        // วิธีที่ 1: กินทีละ 1 ผล
        int result = n;
        
        // วิธีที่ 2: ถ้า n % 2 == 0
        if (n % 2 == 0) {
            result = min(result, 1 + minDays(n / 2));
        } else {
            result = min(result, 1 + minDays(n - 1));
        }
        
        // วิธีที่ 3: ถ้า n % 3 == 0
        if (n % 3 == 0) {
            result = min(result, 1 + minDays(n / 3));
        } else {
            result = min(result, 1 + minDays(n - 1));
        }
        
        
        return memo[n] = result;
    }
};