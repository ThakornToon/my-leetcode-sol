class Solution {
private:
    const int MOD = 1000000007;
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> arr = nums;
        
        for (auto& q : queries) {
            int li = q[0];
            int ri = q[1];
            int ki = q[2];
            int vi = q[3];
            
            for (int idx = li; idx <= ri; idx += ki) {
                arr[idx] = (int)((long long)arr[idx] * vi % MOD);
            }
        }
        
        int result = 0;
        for (int val : arr) {
            result ^= val;
        }
        
        return result;
    }
};