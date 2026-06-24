class Solution {
private:
    const int MOD = 1000000007;
public:
    int countHomogenous(string s) {
        long long result = 0;
        long long count = 1; // ความยาวของกลุ่มปัจจุบัน
        
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                count++;
            } else {
                // จบกลุ่ม: n*(n+1)/2
                result = (result + (count * (count + 1) / 2) % MOD) % MOD;
                count = 1;
            }
        }
        
        // กลุ่มสุดท้าย
        result = (result + (count * (count + 1) / 2) % MOD) % MOD;
        
        return (int)result;
    }
};