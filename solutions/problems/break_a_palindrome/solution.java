class Solution {
    public String breakPalindrome(String palindrome) {
        int n = palindrome.length();
        
        // กรณีความยาว 1 ไม่สามารถเปลี่ยนได้
        if (n == 1) {
            return "";
        }
        
        char[] chars = palindrome.toCharArray();
        
        // หา char ที่ไม่ใช่ 'a' ตัวแรกในครึ่งแรก
        for (int i = 0; i < n / 2; i++) {
            if (chars[i] != 'a') {
                chars[i] = 'a';
                return new String(chars);
            }
        }
        
        // ถ้าทุกตัวในครึ่งแรกเป็น 'a' ให้เปลี่ยนตัวสุดท้ายเป็น 'b'
        chars[n - 1] = 'b';
        return new String(chars);
    }
}