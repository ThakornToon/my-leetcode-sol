class Solution {
public:
    int numSquarefulPerms(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        vector<int> current;
        int count = 0;
        
        backtrack(nums, used, current, count);
        return count;
    }
private:
    bool isSquare(int n) {
        int root = sqrt(n);
        return root * root == n;
    }
    
    void backtrack(vector<int>& nums, vector<bool>& used, 
                   vector<int>& current, int& count) {
        if (current.size() == nums.size()) {
            count++;
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            
            // Skip duplicates
            if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;
            
            // Check squareful condition
            if (!current.empty() && !isSquare(current.back() + nums[i])) {
                continue;
            }
            
            used[i] = true;
            current.push_back(nums[i]);
            backtrack(nums, used, current, count);
            current.pop_back();
            used[i] = false;
        }
    }
};