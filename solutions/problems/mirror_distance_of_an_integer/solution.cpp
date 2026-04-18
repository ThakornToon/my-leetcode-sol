class Solution {
public:
    int mirrorDistance(int n) {
        string s = to_string(n);
        string rev = s;
        reverse(rev.begin(), rev.end());
        
        int reversed = stoi(rev);
        return abs(n - reversed);
    }
};