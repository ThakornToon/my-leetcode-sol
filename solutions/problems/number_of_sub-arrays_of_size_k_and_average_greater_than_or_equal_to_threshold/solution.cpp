class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int targetSum = k * threshold;
        vector<int> prefix(n + 1, 0);
        
        partial_sum(arr.begin(), arr.end(), prefix.begin() + 1);
        
        int count = 0;
        for (int i = 0; i + k <= n; i++) {
            if (prefix[i + k] - prefix[i] >= targetSum) {
                count++;
            }
        }
        
        return count;
    }
};