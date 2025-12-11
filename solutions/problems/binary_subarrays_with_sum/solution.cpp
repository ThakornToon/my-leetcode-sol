class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        // prefix sum มากสุดคือ n (ถ้าทุกตัวเป็น 1)
        vector<int> count(n + 1, 0);
        count[0] = 1;
        
        int prefixSum = 0;
        int result = 0;
        
        for (int num : nums) {
            prefixSum += num;
            
            // ตรวจสอบ bounds
            if (prefixSum - goal >= 0) {
                result += count[prefixSum - goal];
            }
            
            count[prefixSum]++;
        }
        
        return result;
    }
};