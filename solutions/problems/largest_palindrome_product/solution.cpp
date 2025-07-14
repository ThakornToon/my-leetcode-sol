class Solution {
private:
    bool hasNDigitFactors(long long num, int n) {
        long long upper = pow(10, n) - 1;
        long long lower = pow(10, n - 1);
        
        for (long long i = upper; i >= lower; i--) {
            if (num % i == 0) {
                long long other = num / i;
                if (other >= lower && other <= upper) {
                    return true;
                }
            }
            if (i * i < num) break;
        }
        return false;
    }
public:
    int largestPalindrome(int n) {
        if (n == 1) return 9;
        
        long long upper = pow(10, n) - 1;
        long long lower = pow(10, n - 1);
        long long max_product = upper * upper;

        for (long long i = upper; i >= lower; i--) {
            string s = to_string(i);
            string rev = s;
            reverse(rev.begin(), rev.end());
            
            // สร้าง palindrome โดยต่อเฉพาะ n ตัวแรกของ reversed
            string palindrome_str = s + rev.substr(0, n);
            long long palindrome = stoll(palindrome_str);
            
            if (palindrome > max_product) continue;
            
            if (hasNDigitFactors(palindrome, n)) {
                return (int)(palindrome % 1337);
            }
        }
        
        return 0;
    }
};