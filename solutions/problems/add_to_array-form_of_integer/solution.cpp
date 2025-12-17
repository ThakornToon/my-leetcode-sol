class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> res;
        
        // เริ่มจากหลักหน่วย
        for (int i = num.size() - 1; i >= 0 || k > 0; i--) {
            if (i >= 0) {
                k += num[i];
            }
            res.push_back(k % 10);
            k /= 10;
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};