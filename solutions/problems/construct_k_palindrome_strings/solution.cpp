class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.length();
        if (k > n) return false;
        
        // ใช้ bitset เก็บ parity ของแต่ละตัวอักษร
        int oddMask = 0;
        for (char c : s) {
            oddMask ^= (1 << (c - 'a'));
        }
        
        // นับจำนวน bit ที่เป็น 1
        int oddCount = __builtin_popcount(oddMask);
        
        return oddCount <= k;
    }
};