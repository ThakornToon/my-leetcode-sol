class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        int count = 0;
        for (const int n : nums) {
            if (n == 1) {
                count++;
            } else {
                res = max(res, count);
                count = 0;
            }
        }
        return max(res, count);
    }
};