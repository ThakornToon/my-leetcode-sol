class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int, vector<int>> diag;
        
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                diag[i + j].push_back(nums[i][j]);
            }
        }
        
        vector<int> result;
        for (auto& [sum, vec] : diag) {
            reverse(vec.begin(), vec.end());
            result.insert(result.end(), vec.begin(), vec.end());
        }
        
        return result;
    }
};