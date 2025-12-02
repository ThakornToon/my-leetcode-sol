class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size();
        // prefix sum จากหลังมาหน้า
        long long prefixSum = 0;
        
        // 2. Shift แต่ละตัวอักษร
        for (int i = n - 1; i >= 0; i--) {
            prefixSum += shifts[i];
            prefixSum %= 26;  // mod 26 เพราะเกิน 26 จะวนกลับ
            s[i] = 'a' + (s[i] - 'a' + prefixSum) % 26;
        }
        
        return s;
    }
};