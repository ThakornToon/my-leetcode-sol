class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> store;
        backtrack(result, store, candidates, target, 0);
        return result;
    }
private:
    void backtrack(vector<vector<int>> &result, vector<int> &store, vector<int> &candidates, int target, int start){
        if (target == 0){
            result.push_back(store);
            return;
        }
        for (int i = start;  i < candidates.size(); i++){
            if (target - candidates[i] >= 0){
                store.push_back(candidates[i]);
                backtrack(result, store, candidates, target-candidates[i], i);
                store.pop_back();
            }
        }
    }
};