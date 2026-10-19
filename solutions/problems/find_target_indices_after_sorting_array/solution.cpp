class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int count = 0;
        int less_than = 0;
        
        for (int num : nums) {
            if (num < target) {
                less_than++;
            } else if (num == target) {
                count++;
            }
        }
        
        vector<int> result;
        for (int i = 0; i < count; ++i) {
            result.push_back(less_than + i);
        }
        return result;
    }
};