class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> stk;
        int n = nums.size();
        
        // monotonic decreasing stack (by value)
        for (int i = 0; i < n; i++) {
            if (stk.empty() || nums[stk.top()] > nums[i]) {
                stk.push(i);
            }
        }
        
        int maxWidth = 0;
        // scan from right to left
        for (int j = n - 1; j >= 0; j--) {
            while (!stk.empty() && nums[stk.top()] <= nums[j]) {
                int i = stk.top();
                stk.pop();
                maxWidth = max(maxWidth, j - i);
            }
        }
        
        return maxWidth;
    }
};