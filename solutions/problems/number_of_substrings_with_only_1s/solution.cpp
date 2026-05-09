class Solution {
private:
    const int MOD = 1000000007;
public:
    int numSub(string s) {
        long long result = 0;
        long long count = 0;
        
        for (char c : s) {
            if (c == '1') {
                count++;
            } else {
                if (count > 0) {
                    result = (result + count * (count + 1) / 2) % MOD;
                    count = 0;
                }
            }
        }
        
        // segment สุดท้าย
        if (count > 0) {
            result = (result + count * (count + 1) / 2) % MOD;
        }
        
        return result;
    }
};