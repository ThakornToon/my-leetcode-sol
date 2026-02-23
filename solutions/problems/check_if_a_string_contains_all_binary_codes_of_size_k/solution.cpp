class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        int total = 1 << k;  // 2^k
        
        // ตรวจสอบเบื้องต้น
        if (n < total + k - 1) {
            return false;
        }
        
        unordered_set<string> seen;
        
        for (int i = 0; i <= n - k; i++) {
            seen.insert(s.substr(i, k));
        }
        
        return seen.size() == total;
    }
};