class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        // ใช้ binary search หา x
        int left = 0, right = n;
        
        while (left <= right) {
            int x = left + (right - left) / 2;
            
            // หาจำนวนตัวเลขที่ >= x
            int count = 0;
            for (int num : nums) {
                if (num >= x) count++;
            }
            
            if (count == x) {
                return x;
            }
            else if (count > x) {
                left = x + 1;
            }
            else {
                right = x - 1;
            }
        }
        
        return -1;
    }
};