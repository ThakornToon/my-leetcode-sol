class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        
        int pattern1 = 0;  // nums[0] > nums[1] < nums[2] > ...
        int pattern2 = 0;  // nums[0] < nums[1] > nums[2] < ...
        
        // Pattern 1: Even indices เป็น peaks
        // ดังนั้น odd indices (1,3,5,...) ควรเป็น valleys
        for (int i = 1; i < n; i += 2) {  // เฉพาะ odd indices
            int left = nums[i-1];
            int right = (i < n-1) ? nums[i+1] : INT_MAX;
            int target = min(left, right) - 1;
            
            if (nums[i] > target) {
                pattern1 += nums[i] - target;
            }
        }
        
        // Pattern 2: Odd indices เป็น peaks  
        // ดังนั้น even indices (0,2,4,...) ควรเป็น valleys
        for (int i = 0; i < n; i += 2) {  // เฉพาะ even indices
            int left = (i > 0) ? nums[i-1] : INT_MAX;
            int right = (i < n-1) ? nums[i+1] : INT_MAX;
            int target = min(left, right) - 1;
            
            if (nums[i] > target) {
                pattern2 += nums[i] - target;
            }
        }
        
        return min(pattern1, pattern2);
    }
};