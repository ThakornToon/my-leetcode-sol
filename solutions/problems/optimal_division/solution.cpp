class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        if (nums.size() == 1) return to_string(nums[0]);
        if (nums.size() == 2) return to_string(nums[0]) + "/" + to_string(nums[1]);
        
        string denominator = to_string(nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            denominator += "/" + to_string(nums[i]);
        }
        
        return to_string(nums[0]) + "/(" + denominator + ")";
    }
};