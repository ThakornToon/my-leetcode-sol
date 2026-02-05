class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        
        for (int i = 0; i < n; i++) {
            int val = nums[i];
            
            if (val == 0) {
                result[i] = 0;
            } else if (val > 0) {
                // เลื่อนขวา
                int newIndex = (i + val) % n;
                result[i] = nums[newIndex];
            } else {
                // เลื่อนซ้าย
                int steps = abs(val);
                // ใช้ modulo เพื่อลด steps
                steps = steps % n;
                int newIndex = (i - steps + n) % n;
                result[i] = nums[newIndex];
            }
        }
        
        return result;
    }
};