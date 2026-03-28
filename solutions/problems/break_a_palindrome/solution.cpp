class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.length();
        
        // กรณีความยาว 1 ไม่สามารถเปลี่ยนได้
        if (n == 1) {
            return "";
        }
        
        string result = palindrome;
        
        // หา char ที่ไม่ใช่ 'a' ตัวแรกในครึ่งแรก
        for (int i = 0; i < n / 2; i++) {
            if (result[i] != 'a') {
                result[i] = 'a';
                return result;
            }
        }
        
        // ถ้าทุกตัวในครึ่งแรกเป็น 'a' ให้เปลี่ยนตัวสุดท้ายเป็น 'b'
        result[n - 1] = 'b';
        return result;
    }
};