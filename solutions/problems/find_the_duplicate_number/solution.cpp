class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1;
        int right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = 0;
            
            // นับจำนวนสมาชิก ≤ mid
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] <= mid) {
                    count++;
                }
            }
            
            if (count > mid) {
                // ตัวซ้ำอยู่ใน [1, mid]
                right = mid;
            } else {
                // ตัวซ้ำอยู่ใน [mid+1, n]
                left = mid + 1;
            }
        }
        
        return left;
    }
};