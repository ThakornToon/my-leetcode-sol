class Solution {
private: 
    void backtrack(string& num, int idx, long long target,  vector<string>& ans, string curr,  long long val, long long multed) {
        if (idx == num.size()) {
            if (val == target) {
                ans.push_back(curr);
            }
            return;
        }

        for (int i = idx; i < num.size(); i++) {
            // หลีกเลี่ยงเลขนำด้วย 0 เช่น "05"
            if (i != idx && num[idx] == '0') break;

            string numStr = num.substr(idx, i - idx + 1);
            long long currNum = stoll(numStr);

            if (idx == 0) {
                backtrack(num, i + 1, target, ans, numStr, currNum, currNum);
            } else {
                // การบวก
                backtrack(num, i + 1, target, ans, curr + "+" + numStr, val + currNum, currNum);
                
                // การลบ
                backtrack(num, i + 1, target, ans, curr + "-" + numStr, val - currNum, -currNum);
                
                // การคูณ - ตรวจสอบ overflow ก่อนคำนวณ
                if (multed == 0 || 
                    (currNum <= LLONG_MAX / abs(multed))) {
                    long long newMulted = multed * currNum;
                    backtrack(num, i + 1, target, ans, curr + "*" + numStr, val - multed + newMulted, newMulted);
                }
            }
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        backtrack(num, 0, (long long)target, ans, "", 0, 0);
        return ans;
    }
};