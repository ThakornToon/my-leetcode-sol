class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums, 0, current, result);
        return result;
    }
    
private:
    void backtrack(vector<int>& nums, int start, vector<int>& current, vector<vector<int>>& result) {
        if (current.size() >= 2) {
            result.push_back(current);
        }
        
        unordered_set<int> used; // เพื่อป้องกัน duplicates
        for (int i = start; i < nums.size(); i++) {
            // ตรวจสอบว่าไม่ซ้ำและเป็น non-decreasing
            if (used.find(nums[i]) != used.end()) continue;
            if (!current.empty() && nums[i] < current.back()) continue;
            
            used.insert(nums[i]);
            current.push_back(nums[i]);
            backtrack(nums, i + 1, current, result);
            current.pop_back();
        }
    }
};