class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        // เรียงลำดับอาร์เรย์
        std::sort(nums.begin(), nums.end());

        // สร้างอาร์เรย์ชั่วคราว
        std::vector<int> temp = nums;

        // คำนวณตำแหน่งกลาง
        int half = (nums.size() + 1) / 2;
        int small = half - 1;
        int large = nums.size() - 1;

        // จัดเรียงใหม่แบบ wiggle
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = (i % 2 == 0) ? temp[small--] : temp[large--];
        }
    }
};