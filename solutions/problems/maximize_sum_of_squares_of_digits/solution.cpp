class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) return "";
        
        int k = sum / 9;
        int rem = sum % 9;
        
        string res = "";
        for (int i = 0; i < k; ++i) {
            res += '9';
        }
        if (rem > 0) {
            res += to_string(rem);
        }
        while (res.length() < num) {
            res += '0';
        }
        return res;
    }
};