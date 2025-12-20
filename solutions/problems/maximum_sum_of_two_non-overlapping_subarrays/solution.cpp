class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        
        // prefix sum
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        
        auto getSum = [&](int l, int r) {
            return prefix[r + 1] - prefix[l];
        };
        
        int result = 0;
        
        // Case 1: firstLen before secondLen
        int maxFirst = 0;
        for (int i = firstLen + secondLen - 1; i < n; i++) {
            int firstEnd = i - secondLen;
            int firstStart = firstEnd - firstLen + 1;
            maxFirst = max(maxFirst, getSum(firstStart, firstEnd));
            
            int secondSum = getSum(i - secondLen + 1, i);
            result = max(result, maxFirst + secondSum);
        }
        
        // Case 2: secondLen before firstLen
        int maxSecond = 0;
        for (int i = firstLen + secondLen - 1; i < n; i++) {
            int secondEnd = i - firstLen;
            int secondStart = secondEnd - secondLen + 1;
            maxSecond = max(maxSecond, getSum(secondStart, secondEnd));
            
            int firstSum = getSum(i - firstLen + 1, i);
            result = max(result, maxSecond + firstSum);
        }
        
        return result;

    }
};