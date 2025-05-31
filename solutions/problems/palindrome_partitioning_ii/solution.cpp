class Solution {
public:
    int isPalFn(string &str, int s, int e, vector<vector<int>> &isPalin) {
        if (s >= e) {
            return 1;
        }
        if (isPalin[s][e] != -1) {
            return isPalin[s][e];
        }
        if (str[s] == str[e]) {
            return isPalin[s][e] = isPalFn(str, s+1, e-1, isPalin);
        } else {
            return isPalin[s][e] = 0;
        }
    }
    int minCut(string s) {
        int n = s.length();
        vector<vector<int>> isPalin(n, vector<int>(n, -1)); //index [start][end] in string is palindrome?
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                isPalFn(s, i, j, isPalin);
            }
        }
        vector<int> cuts(n, 0);
        for (int i = 0; i < n; i++) {
            if (isPalin[0][i]) {
                cuts[i] = 0;
            } else {
                cuts[i] = i; // Max cuts possible (cut before every character)
                for (int j = 1; j <= i; j++) {
                    if (isPalin[j][i]) {
                        cuts[i] = min(cuts[i], cuts[j - 1] + 1);
                    }
                }
            }
        }
        
        return cuts[n-1];
    }
};