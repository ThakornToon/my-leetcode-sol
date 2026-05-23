class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        
        // มี position ที่ nums[i] > nums[i+1] เกิดขึ้นได้มากสุด 1 ครั้ง
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                count++;
            }
        }
        
        // ตรวจสอบจุดเชื่อมต่อ (rotate point)
        if (nums[n - 1] > nums[0]) {
            count++;
        }
        
        return count <= 1;
    }
};