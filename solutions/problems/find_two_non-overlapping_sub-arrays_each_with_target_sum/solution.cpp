class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
         int n = arr.size();
        vector<int> best(n, INT_MAX);
        int left = 0, sum = 0;
        int minLen = INT_MAX;
        int bestSoFar = INT_MAX;
        
        for (int right = 0; right < n; right++) {
            sum += arr[right];
            
            while (sum > target) {
                sum -= arr[left];
                left++;
            }
            
            if (sum == target) {
                int curLen = right - left + 1;
                if (left > 0 && best[left - 1] != INT_MAX) {
                    minLen = min(minLen, best[left - 1] + curLen);
                }
                bestSoFar = min(bestSoFar, curLen);
            }
            
            best[right] = bestSoFar;
        }
        
        return minLen == INT_MAX ? -1 : minLen;
    }
};