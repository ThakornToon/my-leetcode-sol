class Solution {
private:
    bool isPredecessor(const string& a, const string& b) {
        if (a.size() + 1 != b.size()) return false;
        
        int i = 0, j = 0;
        bool diffFound = false;
        
        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                i++;
                j++;
            } else {
                if (diffFound) return false;
                diffFound = true;
                j++;  // skip one character in b
            }
        }
        
        return true;
    }
public:
    int longestStrChain(vector<string>& words) {
        // เรียงตามความยาว
        sort(words.begin(), words.end(), 
             [](const string& a, const string& b) {
                 return a.size() < b.size();
             });
        
        int n = words.size();
        vector<int> dp(n, 1);  // each word is a chain of length 1
        int maxLength = 1;
        
        // ดูว่า chain ต่อจากคำก่อนหน้าได้ไหม
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (isPredecessor(words[j], words[i])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLength = max(maxLength, dp[i]);
        }
        
        return maxLength;
    }
};