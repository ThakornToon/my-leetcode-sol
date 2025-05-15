class Solution {
private:
    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& sub, vector<vector<int>>& res) {
        if (sub.size() == nums.size()) {
            res.push_back(sub);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            used[i] = true;
            sub.push_back(nums[i]);
            backtrack(nums, used, sub, res);
            sub.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sub;
        vector<bool> used(nums.size(), false);
        backtrack(nums, used, sub, res);
        return res;
    }
};