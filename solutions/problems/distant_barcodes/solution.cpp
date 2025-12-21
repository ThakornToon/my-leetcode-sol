class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n = barcodes.size();
        unordered_map<int, int> freq;
        int maxFreq = 0, maxVal = 0;
        
        for (int num : barcodes) {
            freq[num]++;
            if (freq[num] > maxFreq) {
                maxFreq = freq[num];
                maxVal = num;
            }
        }
        
        if (maxFreq > (n + 1) / 2) {
            return {};
        }
        
        vector<int> result(n);
        int idx = 0;
        
        while (freq[maxVal] > 0) {
            result[idx] = maxVal;
            freq[maxVal]--;
            idx += 2;
        }
        
        for (auto& [num, count] : freq) {
            while (count > 0) {
                if (idx >= n) idx = 1;  // Ensure odd positions
                result[idx] = num;
                count--;
                idx += 2;
            }
        }
        
        return result;
    }
};