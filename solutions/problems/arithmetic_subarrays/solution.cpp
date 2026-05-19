class Solution {
private:
    bool isArithmetic(vector<int>& nums, int l, int r) {
        int len = r - l + 1;
        if (len <= 2) return true;
        
        // คัดลอก subarray
        vector<int> sub(nums.begin() + l, nums.begin() + r + 1);
        
        // เรียงลำดับ
        sort(sub.begin(), sub.end());
        
        // คำนวณ difference
        int diff = sub[1] - sub[0];
        
        // ตรวจสอบทุกคู่
        for (int i = 2; i < len; i++) {
            if (sub[i] - sub[i-1] != diff) {
                return false;
            }
        }
        
        return true;
    }

public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> result;
        result.reserve(l.size());
        
        for (int i = 0; i < l.size(); i++) {
            result.push_back(isArithmetic(nums, l[i], r[i]));
        }
        
        return result;
    }
};