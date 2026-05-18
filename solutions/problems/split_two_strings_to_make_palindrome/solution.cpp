class Solution {
private:
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    
    // x(prefix) + y(suffix)
    bool check(const string& x, const string& y) {
        int left = 0, right = x.length() - 1;
        
        // ดูว่าตัดมาถึงได้แค่ไหน x(prefix) + y(suffix) = palindrome
        while (left < right && x[left] == y[right]) {
            left++;
            right--;
        }
    
        // ตัดตำแหน่งเดียวกันได้
        // a = 123456...
        // b = ...654321
        if (left >= right) {
            return true;
        }
        
        // XXX......(เอา prefix) กับ ......XXX(เอา suffix) ลองตัดที่ left หรือ right 
        return isPalindrome(x, left, right) || isPalindrome(y, left, right);
    }

public:
    bool checkPalindromeFormation(string a, string b) {
        // a(prefix) + b(suffix) หรือ b(prefix) + a(suffix)
        return check(a, b) || check(b, a);
    }
};