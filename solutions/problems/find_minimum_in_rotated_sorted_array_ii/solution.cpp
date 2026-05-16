class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] > nums[right]) {
                // ค่าน้อยอยู่ทางขวา
                left = mid + 1;
            } else if (nums[mid] < nums[right]) {
                // ค่าน้อยอยู่ทางซ้าย
                right = mid;
            } else {
                // nums[mid] == nums[right] -> ไม่รู้ทาง
                // right ปลอดภัยกว่าเลื่อน left ในทั้งสองกรณี
                right--;
            }
        }
        
        return nums[left];
    }
};