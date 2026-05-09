class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        
        // ถ้ามี element ≤ 4 ตัว สามารถเปลี่ยนให้เท่ากันหมดได้
        if (n <= 4) {
            return 0;
        }
        
        // เรียงลำดับ
        sort(nums.begin(), nums.end());
        
        // พิจารณา 4 กรณี
        int option1 = nums[n - 1 - 3] - nums[0];      // ลบ 3 ตัวสุดท้าย
        int option2 = nums[n - 1 - 2] - nums[1];      // ลบ 1 ตัวแรก + 2 ตัวสุดท้าย
        int option3 = nums[n - 1 - 1] - nums[2];      // ลบ 2 ตัวแรก + 1 ตัวสุดท้าย
        int option4 = nums[n - 1] - nums[3];          // ลบ 3 ตัวแรก
        
        return min({option1, option2, option3, option4});
    }
};