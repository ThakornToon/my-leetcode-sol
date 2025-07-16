class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int total = accumulate(machines.begin(), machines.end(), 0);
        int n = machines.size();
        if (total % n != 0) return -1;
        
        int target = total / n;
        int result = 0;
        int sum = 0;
        
        for (int i = 0; i < n; ++i) {
            int diff = machines[i] - target;
            sum += diff;
            result = max({result, abs(sum), diff});
        }
        
        return result;
    }
};