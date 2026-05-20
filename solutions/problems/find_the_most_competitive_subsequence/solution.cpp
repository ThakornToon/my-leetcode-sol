class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> stack;
        
        for (int i = 0; i < n; i++) {
            // pop while: stack not empty, current < top พบค่าน้อยกว่าไปแทน, และยังมีส่วนที่เหลือพอสำหรับความยาว
            while (!stack.empty() && nums[i] < stack.back() && 
                   stack.size() + (n - i) > k) {
                stack.pop_back();
            }
            
            if (stack.size() < k) {
                stack.push_back(nums[i]);
            }
        }
        
        return stack;
    }
};