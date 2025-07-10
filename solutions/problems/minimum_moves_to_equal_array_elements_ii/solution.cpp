class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // เรียงลำดับอาร์เรย์
        
        int median = nums[nums.size() / 2];  // หาค่ามัธยฐาน
        int moves = 0;
        
        // คำนวณผลรวมความแตกต่างจากมัธยฐาน
        for (int& num : nums) {
            moves += abs(num - median);
        }
        
        return moves;
    }
};