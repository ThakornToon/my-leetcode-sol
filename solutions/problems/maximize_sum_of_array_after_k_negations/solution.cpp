class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        // 1. เรียงจากน้อยไปมาก
        sort(nums.begin(), nums.end());
        
        // 2. Negate negative numbers ก่อน
        for (int i = 0; i < nums.size() && k > 0; i++) {
            if (nums[i] < 0) {
                nums[i] = -nums[i];
                k--;
            }
        }
        
        // 3. หาก k เหลือและเป็นคี่, negate ค่าที่น้อยที่สุด
        if (k % 2 == 1) {
            // เรียงใหม่เพื่อหาค่าน้อยที่สุด (หรือใช้ min_element)
            sort(nums.begin(), nums.end());
            nums[0] = -nums[0];
        }
        
        // 4. คำนวณ sum
        return accumulate(nums.begin(), nums.end(), 0);
    }
};