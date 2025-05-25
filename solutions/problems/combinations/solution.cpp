class Solution {
private:
    void backtrack(int start, int k, int nums, vector<int>& sub, vector<vector<int>>& res) {
        if (sub.size() == k) {
            res.push_back(sub);
            return;
        }
        for (int i = start; i <= nums; i++) {
            sub.push_back(i);
            backtrack(i+1, k, nums, sub, res);
            sub.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> sub;
        backtrack(1, k, n, sub, res);
        return res;
    }
};