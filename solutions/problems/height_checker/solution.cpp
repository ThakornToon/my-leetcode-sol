class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> freq(101, 0);
        
        // Count frequencies
        for (int height : heights) {
            freq[height]++;
        }
        
        int count = 0;
        int expectedHeight = 1;  // smallest possible height
        int idx = 0;
        
        while (expectedHeight <= 100) {
            while (freq[expectedHeight] > 0) {
                if (heights[idx] != expectedHeight) {
                    count++;
                }
                idx++;
                freq[expectedHeight]--;
            }
            expectedHeight++;
        }
        
        return count;
    }
};