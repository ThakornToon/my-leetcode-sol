class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int maxLen = 0;
        int posLen = 0;  // positive product length ending here
        int negLen = 0;  // negative product length ending here
        
        for (int num : nums) {
            if (num > 0) {
                posLen++;
                negLen = (negLen > 0) ? negLen + 1 : 0;
            } else if (num < 0) {
                int newPosLen = (negLen > 0) ? negLen + 1 : 0;
                int newNegLen = posLen + 1;
                posLen = newPosLen;
                negLen = newNegLen;
            } else {
                posLen = 0;
                negLen = 0;
            }
            
            maxLen = max(maxLen, posLen);
        }
        
        return maxLen;

    }
};