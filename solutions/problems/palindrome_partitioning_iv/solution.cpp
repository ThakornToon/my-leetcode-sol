class Solution {
public:
    bool checkPartitioning(string s) {
int n = s.length();
        vector<bool> prefix(n, false);  // prefix[i] = s[0..i] is palindrome?
        vector<bool> suffix(n, false);  // suffix[i] = s[i..n-1] is palindrome?
        
        // คำนวณ prefix
        for (int i = 0; i < n; i++) {
            // odd length
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (l == 0) prefix[r] = true;
                l--; r++;
            }
            // even length
            l = i; r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (l == 0) prefix[r] = true;
                l--; r++;
            }
        }
        
        // คำนวณ suffix
        for (int i = 0; i < n; i++) {
            // odd length
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r == n - 1) suffix[l] = true;
                l--; r++;
            }
            // even length
            l = i; r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r == n - 1) suffix[l] = true;
                l--; r++;
            }
        }
        
        // ลองทุกตำแหน่ง middle
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                if (prefix[i] && isPal(s, i + 1, j) && suffix[j + 1]) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
private:
    bool isPal(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }
};