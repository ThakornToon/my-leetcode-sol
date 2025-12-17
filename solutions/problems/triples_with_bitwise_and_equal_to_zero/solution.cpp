class Solution {
public:
    int countTriplets(vector<int>& nums) {
        unordered_map<int, int> freq;
        int n = nums.size();
        
        // Count pairwise AND
        for (int a : nums) {
            for (int b : nums) {
                freq[a & b]++;
            }
        }
        
        int count = 0;
        // For each num, check all masks in freq
        for (int num : nums) {
            for (auto& [mask, cnt] : freq) {
                if ((num & mask) == 0) {
                    count += cnt;
                }
            }
        }
        
        return count;
    }
};