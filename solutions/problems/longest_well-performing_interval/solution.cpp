class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        
        // Step 1: สร้าง prefix sum array
        // prefix[i] = sum of scores from index 0 to i-1
        vector<int> prefix(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            int score = (hours[i] > 8) ? 1 : -1;
            prefix[i + 1] = prefix[i] + score;
        }
        
        // Step 2: ใช้ monotonic stack หา decreasing sequence
        vector<int> stack;
        for (int i = 0; i <= n; i++) {
            if (stack.empty() || prefix[stack.back()] > prefix[i]) {
                stack.push_back(i);
            }
        }
        
        // Step 3: หาความยาวสูงสุดโดยไล่จากขวาไปซ้าย
        int maxLen = 0;
        for (int i = n; i >= 0; i--) {
            while (!stack.empty() && prefix[stack.back()] < prefix[i]) {
                // หา j < i ที่ 0 < prefix[i] - prefix[j] และทำให้ i - j มากที่สุด
                maxLen = max(maxLen, i - stack.back());
                stack.pop_back();
            }
        }
        
        return maxLen;
    }
};