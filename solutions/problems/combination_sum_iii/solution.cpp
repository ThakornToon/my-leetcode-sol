class Solution {
private:
    void backtrack(int k, int n, vector<vector<int>>& res, vector<int>& store, int start) {
        if (k == 0) {
            if (n!=0) {
                return;
            }
            res.push_back(store);
            return;
        }
        for (int i = start; i <= 9; i++) {
            if (n - i < 0) {
                return;
            }
            store.push_back(i);
            backtrack(k-1, n-i, res, store, i+1);
            store.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> store;
        backtrack(k, n, res, store, 1);
        return res;
    }
};