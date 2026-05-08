class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int minVal = *min_element(arr.begin(), arr.end());
        int maxVal = *max_element(arr.begin(), arr.end());
        int n = arr.size();
        
        if (maxVal == minVal) return true;
        
        if ((maxVal - minVal) % (n - 1) != 0) return false;
        
        int diff = (maxVal - minVal) / (n - 1);
        unordered_set<int> seen(arr.begin(), arr.end());
        
        for (int i = 0; i < n; i++) {
            if (seen.find(minVal + i * diff) == seen.end()) {
                return false;
            }
        }
        return true;
    }
};