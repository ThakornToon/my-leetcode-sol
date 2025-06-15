class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        res.push_back(0);
        int i = 0;
        int end = 1;
        while (res.size() != n + 1) {
            res.push_back(res[i++] + 1);
            if (i == end) {
                end += i;
                i = 0;
            }
        }
        return res;
    }
};