class Solution {
private:
    bool check(int step, int n, vector<int>& nums, int zero_idx) {
        for (int i = 1; i < n; ++i) {
            int prev = (zero_idx + (i - 1) * step + n) % n;
            int curr = (zero_idx + i * step + n) % n;
            if (nums[prev] > nums[curr]) return false;
        }
        return true;
    }
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int zero = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                zero = i;
                break;
            }
        }
        
        int ans = INT_MAX;
        
        // กรณีเรียงไปทางขวา (Step = 1)
        if (check(1, n, nums, zero)) {
            ans = min(ans, zero);         // Rotate อย่างเดียว
            ans = min(ans, n - zero + 2); // Reverse -> Rotate -> Reverse
        }
        
        // กรณีเรียงไปทางซ้าย (Step = -1)
        if (check(-1, n, nums, zero)) {
            ans = min(ans, zero + 1 + 1);     // Rotate -> Reverse
            ans = min(ans, 1 + n - 1 - zero);     // Reverse -> Rotate
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};