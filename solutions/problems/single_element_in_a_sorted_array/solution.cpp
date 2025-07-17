class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            // สำหรับดัชนีคู่ (0, 2, 4,...) คู่ของมันควรอยู่ที่ดัชนีถัดไป (index+1)
            // สำหรับดัชนีคี่ (1, 3, 5,...) คู่ของมันควรอยู่ที่ดัชนีก่อนหน้า (index-1)
            // mid ^ 1 ทำหน้าที่นี้โดยอัตโนมัติ เราต้องหาว่ามีตัวไปแทรกส่วนไหนให้ลำดับเพี้ยน
            if (nums[mid] == nums[mid ^ 1]) { 
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return nums[low];
    }
};