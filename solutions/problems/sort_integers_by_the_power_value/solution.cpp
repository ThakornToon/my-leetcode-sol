class Solution {
private:
    unordered_map<int, int> memo;
    
public:
    int getPower(int x) {
        if (x == 1) return 0;
        if (memo.count(x)) return memo[x];
        
        int result;
        if (x % 2 == 0) {
            result = 1 + getPower(x / 2);
        } else {
            result = 1 + getPower(3 * x + 1);
        }
        
        memo[x] = result;
        return result;
    }

    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> nums;
        
        for (int i = lo; i <= hi; i++) {
            nums.emplace_back(getPower(i), i);
        }
        
        nth_element(nums.begin(), nums.begin() + k - 1, nums.end());
        
        return nums[k - 1].second;
    }
};