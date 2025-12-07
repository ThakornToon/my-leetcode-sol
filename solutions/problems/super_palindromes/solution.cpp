class Solution {
public:
    int superpalindromesInRange(string left, string right) {
        long long L = stoll(left);
        long long R = stoll(right);
        int count = 0;
        
        // กำหนดขอบเขตของ p
        long long limit = 99999; 
        
        for (long long i = 1; i <= limit; i++) { // สร้าง Palindromes ไปยกกำลังสอง
            // สร้าง palindrome แบบ odd length
            string s = to_string(i);
            string t = s;
            reverse(t.begin(), t.end());
            string odd_str = s + t.substr(1);  // เอาเลขตรงกลางออก 1 ตัว
            long long p_odd = stoll(odd_str);
            long long x_odd = p_odd * p_odd;
            
            if (x_odd > R) break;  // เกินขอบเขตแล้ว
            
            if (x_odd >= L && isPalindrome(x_odd) && isPalindrome(p_odd)) {
                count++;
            }
            
            // สร้าง palindrome แบบ even length
            string even_str = s + t;
            long long p_even = stoll(even_str);
            if (p_even > R / p_even) continue;
            long long x_even = p_even * p_even;
            
            if (x_even >= L && x_even <= R && isPalindrome(x_even) && isPalindrome(p_even)) {
                count++;
            }
        }
        
        return count;
    }
private:
    bool isPalindrome(long long x) {
        if (x < 0) return false;
        long long reversed = 0;
        long long original = x;
        
        while (x > 0) {
            reversed = reversed * 10 + (x % 10);
            x /= 10;
        }
        
        return reversed == original;
    }
};