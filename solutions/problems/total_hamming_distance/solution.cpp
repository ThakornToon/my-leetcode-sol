class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int total = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                total += __builtin_popcount(nums[i] ^ nums[j]);
            }
        }
        return total;
    }
};