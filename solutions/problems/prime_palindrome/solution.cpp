class Solution {
public:
    int primePalindrome(int n) {
        if (n <= 2) return 2;
        if (n <= 3) return 3;
        if (n <= 5) return 5;
        if (n <= 7) return 7;
        if (n <= 11) return 11;
        
        for (int i = n; i <= INT_MAX; i++) {
            // ข้ามเลขที่มีจำนวนหลักเป็นคู่ (ยกเว้น 11)
            if (i > 11 && i < 100) i = 101;
            else if (i > 1000 && i < 10000) i = 10001;
            else if (i > 100000 && i < 1000000) i = 1000001;
            else if (i > 10000000 && i < 100000000) i = 100000001;
            
            if (isPalindrome(i) && isPrime(i)) {
                return i;
            }
        }
        
        return -1;
    }
private:
    bool isPrime(int n) {
        if (n < 2) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;
        
        int limit = sqrt(n);
        for (int i = 3; i <= limit; i += 2) {
            if (n % i == 0) return false;
        }
        return true;
    }
    
    bool isPalindrome(int n) {
        string s = to_string(n);
        string t = s;
        reverse(t.begin(), t.end());
        return s == t;
    }
};