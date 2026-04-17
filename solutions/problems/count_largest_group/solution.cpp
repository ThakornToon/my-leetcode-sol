class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> sumOfDigits(n + 1, 0);
        vector<int> freq(37, 0);
        int maxFreq = 0;
        
        for (int i = 1; i <= n; i++) {
            // sum of digits ของ i = sum of digits ของ i/10 + (i % 10)
            sumOfDigits[i] = sumOfDigits[i / 10] + (i % 10);
            freq[sumOfDigits[i]]++;
            maxFreq = max(maxFreq, freq[sumOfDigits[i]]);
        }
        
        return count(freq.begin(), freq.end(), maxFreq);
    }
};