class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> positions; // num -> {count, first, last}
        int max_degree = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (positions.find(num) == positions.end()) {
                positions[num] = {1, i, i}; // {count, first, last}
            } else {
                positions[num][0]++; // increment count
                positions[num][2] = i; // update last position
            }
            max_degree = max(max_degree, positions[num][0]);
        }
        
        int min_length = INT_MAX;
        for (auto& [num, info] : positions) {
            if (info[0] == max_degree) {
                int length = info[2] - info[1] + 1;
                min_length = min(min_length, length);
            }
        }
        
        return min_length;
    }
};