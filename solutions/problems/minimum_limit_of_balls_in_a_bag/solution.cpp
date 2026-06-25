class Solution {
private:
    bool canDivide(vector<int>& nums, int maxOperations, int limit) {
        long long operations = 0;
        
        for (int num : nums) {
            if (num > limit) {
                // จำนวน operation ที่ต้องใช้
                // ceil(num / limit) - 1 = (num - 1) / limit
                operations += (num - 1) / limit;
                if (operations > maxOperations) {
                    return false;
                }
            }
        }
        
        return operations <= maxOperations;
    }

public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());
        int result = right;
        
        while (left <= right) {
            // เลือกค่า max
            int mid = left + (right - left) / 2;
            
            if (canDivide(nums, maxOperations, mid)) {
                // ใช้ max = mid ได้
                result = mid;
                right = mid - 1;
            } else {
                // ใช้ max = mid ไม่ได้
                left = mid + 1;
            }
        }
        
        return result;
    }
};