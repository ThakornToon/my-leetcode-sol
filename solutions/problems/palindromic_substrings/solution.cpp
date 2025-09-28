class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int total = 0;
        vector<int> group_start, group_end;
        
        // Step 1: Group consecutive same characters
        group_start.push_back(0);
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i-1]) {
                group_end.push_back(i-1);
                group_start.push_back(i);
            }
        }
        group_end.push_back(n-1);
        
        // Step 2: Count palindromes for each group
        int m = group_start.size();
        for (int i = 0; i < m; i++) {
            int start = group_start[i];
            int end = group_end[i];
            int length = end - start + 1;
            
            // Count palindromes within the group
            total += length * (length + 1) / 2;
            
            // Expand to find palindromes across groups
            int left = start - 1;
            int right = end + 1;
            
            while (left >= 0 && right < n && s[left] == s[right]) {
                total++;
                left--;
                right++;
            }
        }
        
        return total;
    }
};