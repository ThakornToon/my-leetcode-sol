class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int current_sum = 0;
        
        // คำนวณผลรวมของ window แรก
        for (int i = 0; i < k; i++) {
            current_sum += nums[i];
        }
        
        int max_sum = current_sum;
        
        // เลื่อน window
        for (int i = k; i < nums.size(); i++) {
            current_sum = current_sum - nums[i - k] + nums[i];
            max_sum = max(max_sum, current_sum);
        }
        
        return static_cast<double>(max_sum) / k;
    }
};