class Solution {
public:
    int biSearch(vector<int>& res, int num) {
        int l = 0;
        int r = res.size() - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (res[m] >= num) {
                r = m;
            }
            else {
                l = m + 1;
            }
        }
        return l;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        res.push_back(nums[0]);
        for (int i = 0; i < nums.size(); i++) {
            if (res.back() < nums[i]) {
                res.push_back(nums[i]);
            } else {
                int idx = biSearch(res, nums[i]);
                res[idx] = nums[i];
            }            
        }
        return res.size();
    }
};