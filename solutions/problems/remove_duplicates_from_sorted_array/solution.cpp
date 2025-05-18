class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int j = 0;
        for (int i=1; i<nums.size(); i++) {
            if (nums[j] != nums[i]) {
                j += 1;
                nums[j] = nums[i];
            }
        }

        return j+1;
    }
};