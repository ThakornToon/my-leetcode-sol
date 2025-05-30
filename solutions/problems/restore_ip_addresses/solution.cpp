class Solution {
private:
    bool check(string &s) {
        int n = s.size();
        if (n == 1) {
            return true;
        }
        if (s[0] == '0') {
            return false;
        }
        int num = stoi(s);
        if (num > 255) {
            return false;
        }
        return true;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        vector<string> ans;
        if (n > 12) {
            return ans;
        }
        for (int d1 = 1; d1 <= 3; d1++) {
            for (int d2 = 1; d2 <= 3; d2++) {
                for (int d3 = 1; d3 <= 3; d3++) {
                    if (d1 + d2 + d3 < n && d1 + d2 + d3 + 3 >= n) {
                        string p1 = s.substr(0, d1);
                        string p2 = s.substr(d1, d2);
                        string p3 = s.substr(d1 + d2, d3);
                        string p4 = s.substr(d1 + d2 + d3);

                        if (check(p1) && check(p2) && check(p3) && check(p4)) {
                            ans.push_back(p1 + "." + p2 + "." + p3 + "." + p4);
                        }
                    }
                }
            }
        }
        return ans;
    }
};

/*
There needs to be 4 parts per IP. There are always three dots/four candidates (2.5.5.2.5.5.1.1.1.3.5 is not valid, neither is 1.1.1)

When selecting a candidate, it can't have more than 3 characters (2552.55.111.35 is not valid)

When selecting a candidate, its characters cant be above 255 (25.525.511.135 is not valid because of 525 and 511)

When selecting a candidate, IF the candidate has 2 or more characters, then the first can't be a zero. (1.0.1.023 is not valid as member 023 is size>1 and leads with 0. But 0.0.0.0 is valid as each candidate is size 1)
*/