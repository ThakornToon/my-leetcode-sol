class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;
        
        const int MAX_VAL = 100000;
        vector<int> evenVersion(MAX_VAL + 1, -1);
        vector<int> oddVersion(MAX_VAL + 1, -1);
        
        // สำหรับแต่ละ starting point
        for (int i = 0; i < n; i++) {
            if (n - i <= maxLen) break;
            
            int evenCount = 0, oddCount = 0;
            
            for (int j = i; j < n; j++) {
                int num = nums[j];
                
                if (num % 2 == 0) {
                    if (evenVersion[num] != i) {  // ใช้ i เป็น version marker
                        evenVersion[num] = i;
                        evenCount++;
                    }
                } else {
                    if (oddVersion[num] != i) {
                        oddVersion[num] = i;
                        oddCount++;
                    }
                }
                
                if (evenCount == oddCount) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        
        return maxLen;
    }
};