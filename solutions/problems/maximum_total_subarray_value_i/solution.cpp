class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        if (nums.empty() || k == 0) return 0;
        
        // หาค่าสูงสุดและต่ำสุดโดยใช้ minmax_element
        auto [minIt, maxIt] = minmax_element(nums.begin(), nums.end());
        
        long long maxDiff = (long long)(*maxIt) - (long long)(*minIt);
        
        return maxDiff * k;
    }
};