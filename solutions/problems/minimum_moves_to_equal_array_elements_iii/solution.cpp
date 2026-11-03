class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max_val = *std::max_element(nums.begin(), nums.end());
        long long moves = 0;
        
        for (int num : nums) {
            moves += (long long)(max_val - num);
        }
        
        return moves;
    }
};