class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        
        for (int num : arr) {
            int rem = num % k;
            if (rem < 0) rem += k;
            freq[rem]++;
        }
        
        for (auto& p : freq) {
            int r = p.first;
            if (r == 0) {
                if (p.second % 2 != 0) return false;
            } else {
                int complement = k - r;
                if (freq[complement] != p.second) return false;
            }
        }
        
        return true;
    }
};