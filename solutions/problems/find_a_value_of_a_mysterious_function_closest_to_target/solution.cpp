class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        unordered_set<int> currSet;
        int minDiff = abs(arr[0] - target);
        
        for (int num : arr) {
            unordered_set<int> nextSet;
            nextSet.insert(num);
            
            for (int val : currSet) {
                nextSet.insert(val & num);
            }
            
            currSet = nextSet;
            
            for (int val : currSet) {
                int diff = abs(val - target);
                if (diff < minDiff) {
                    minDiff = diff;
                }
            }
        }
        return minDiff;
    }
};