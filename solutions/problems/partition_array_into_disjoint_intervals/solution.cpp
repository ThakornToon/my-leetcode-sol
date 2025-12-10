class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        
        // สร้าง array สำหรับเก็บค่าสูงสุดจากซ้าย
        vector<int> maxLeft(n);
        maxLeft[0] = nums[0];
        for (int i = 1; i < n; i++) {
            maxLeft[i] = max(maxLeft[i-1], nums[i]);
        }
        
        // สร้าง array สำหรับเก็บค่าต่ำสุดจากขวา
        vector<int> minRight(n);
        minRight[n-1] = nums[n-1];
        for (int i = n-2; i >= 0; i--) {
            minRight[i] = min(minRight[i+1], nums[i]);
        }
        
        // หา partition point
        for (int i = 0; i < n-1; i++) {
            if (maxLeft[i] <= minRight[i+1]) {
                return i + 1; // ความยาวของ left partition
            }
        }
        
        return n;
    }
};