class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        // Sort by difference (aCost - bCost)
        sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[0] - a[1]) < (b[0] - b[1]);
        });
        
        int total = 0;
        int n = costs.size() / 2;
        
        // First n to city A, last n to city B
        for (int i = 0; i < n; i++) {
            total += costs[i][0];
        }
        for (int i = n; i < 2 * n; i++) {
            total += costs[i][1];
        }
        
        return total;
    }
};