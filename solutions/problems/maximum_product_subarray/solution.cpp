class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currmax = 1;
        int currmin = 1;
        int res = nums[0];
        for (int& n : nums) {
            int temp = currmax * n;
            currmax = max(n, max(temp, currmin * n));
            currmin = min(n, min(temp, currmin * n));
            res = max(currmax, res);
        }
        return res;
    }
};