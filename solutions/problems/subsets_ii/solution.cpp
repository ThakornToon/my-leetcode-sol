class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        createSubset(nums, 0, res, subset);
        return res;  
    }

    void createSubset(vector<int>& nums, int index, vector<vector<int>>& res, vector<int>& subset) {
        res.push_back(subset);
        
        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[i-1]) {
                continue;
            }
            subset.push_back(nums[i]);
            createSubset(nums, i + 1, res, subset);
            subset.pop_back();
        }
        
    }    
};