class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        // สร้าง powers of 2
        vector<long long> pow2(n);
        pow2[0] = 1;
        for (int i = 1; i < n; i++) {
            pow2[i] = (pow2[i-1] * 2) % MOD;
        }
        
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum = (sum + nums[i] * pow2[i]) % MOD;
            sum = (sum - nums[i] * pow2[n-1-i]) % MOD;
        }
        
        return (sum + MOD) % MOD;
    }
};