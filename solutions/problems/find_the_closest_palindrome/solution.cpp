class Solution {
public:
    string nearestPalindromic(string n) {
        long long num = stoll(n);
        int len = n.size();
        
        if (len == 1) return to_string(num - 1);
        
        vector<long long> candidates = {
            (long long)pow(10, len - 1) - 1,  // 999...9
            (long long)pow(10, len) + 1       // 100...001
        };
        
        string prefix = n.substr(0, (len + 1)/2); // 12385 -> 123
        long long half = stoll(prefix);
        for (long long i = half - 1; i <= half + 1; i++) { // 123 -> 122, 123, 124
            string left = to_string(i);
            string mirrored = left + string(left.rbegin() + (len % 2), left.rend()); 
            candidates.push_back(stoll(mirrored));
        }
        
        long long min_diff = LLONG_MAX;
        long long result = 0;
        for (long cand : candidates) {
            if (cand == num) continue;
            
            long long diff = abs(cand - num);
            if (diff < min_diff || (diff == min_diff && cand < result)) {
                min_diff = diff;
                result = cand;
            }
        }
        
        return to_string(result);
    }
};