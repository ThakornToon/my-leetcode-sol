class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        // DP array สำหรับ digit sum
        vector<int> digitSum(highLimit + 1, 0);
        vector<int> freq(50, 0);
        
        for (int i = 1; i <= highLimit; i++) {
            // digitSum[i] = digitSum[i/10] + i%10
            digitSum[i] = digitSum[i / 10] + (i % 10);
            if (i >= lowLimit) {
                freq[digitSum[i]]++;
            }
        }
        
        return *max_element(freq.begin(), freq.end());
    }
};