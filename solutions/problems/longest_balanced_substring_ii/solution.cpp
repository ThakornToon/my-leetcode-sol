class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int max_len = 1;

        // 1 char
        int run = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i-1]) max_len = max(max_len, ++run);
            else run = 1;
        }

        // 2 chars: a,b
        unordered_map<int,int> ab;
        ab[0] = -1;
        int diff = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') diff++;
            else if (s[i] == 'b') diff--;
            else { diff = 0; ab.clear(); ab[0] = i; continue; }

            if (ab.count(diff)) max_len = max(max_len, i - ab[diff]);
            else ab[diff] = i;
        }

        // 2 chars: a,c
        unordered_map<int,int> ac;
        ac[0] = -1;
        diff = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') diff++;
            else if (s[i] == 'c') diff--;
            else { diff = 0; ac.clear(); ac[0] = i; continue; }

            if (ac.count(diff)) max_len = max(max_len, i - ac[diff]);
            else ac[diff] = i;
        }

        // 2 chars: b,c
        unordered_map<int,int> bc;
        bc[0] = -1;
        diff = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'b') diff++;
            else if (s[i] == 'c') diff--;
            else { diff = 0; bc.clear(); bc[0] = i; continue; }

            if (bc.count(diff)) max_len = max(max_len, i - bc[diff]);
            else bc[diff] = i;
        }

        // 3 chars: a,b,c equal
        map<pair<int,int>, int> first3;
        first3[{0,0}] = -1;
        int cnt[3] = {0,0,0};

        vector<int> preA(n+1,0), preB(n+1,0), preC(n+1,0);
        for (int i = 0; i < n; i++) {
            preA[i+1] = preA[i] + (s[i]=='a');
            preB[i+1] = preB[i] + (s[i]=='b');
            preC[i+1] = preC[i] + (s[i]=='c');
        }
        
        for (int i = 0; i < n; i++) {
            cnt[s[i]-'a']++;
            int dAB = cnt[0] - cnt[1];
            int dAC = cnt[0] - cnt[2];
            auto key = make_pair(dAB, dAC);
            if (first3.count(key)) {
                int start = first3[key];
                max_len = max(max_len, i - start);
            } else {
                first3[key] = i;
            }
        }

        return max_len;
    }
};