class Solution {
private:
    const int MOD = 1000000007;
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        vector<int> pow2(n + 1);
        pow2[0] = 1;
        for (int i = 1; i <= n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }
        
        int result = 0;

        // binary search
        for (int left = 0; left < n; left++) {
            if (nums[left] * 2 > target) break;
            
            // index
            int lo = left;
            int hi = n - 1;

            // mid
            int right = left;

            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (nums[left] + nums[mid] <= target) {
                    right = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            
            if (right >= left) {
                result = (result + pow2[right - left]) % MOD;
            }
        }
        
        return result;
    }
};