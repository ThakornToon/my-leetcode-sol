class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> result(2);
        
        // ใช้ marking ด้วย index
        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0) {
                result[0] = abs(nums[i]);  // ตัวที่ซ้ำ
            } else {
                nums[index] = -nums[index];  // mark
            }
        }
        
        // หาตัวที่หายไป
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                result[1] = i + 1;
                break;
            }
        }
        
        return result;
    }
};