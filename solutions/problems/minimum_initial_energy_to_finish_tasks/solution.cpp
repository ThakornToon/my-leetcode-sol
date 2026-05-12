class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        // after = before - actual
        // before >= minimum
        // after >= minimum - actual
        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) {
        return (a[1] - a[0]) > (b[1] - b[0]);  // diff มากไปน้อย
    });
    
        int energy = 0;
        for (int i = tasks.size() - 1; i >= 0; i--) {
            int actual = tasks[i][0];
            int minimum = tasks[i][1];
            energy = max(energy + actual, minimum);
        }
        return energy;
    }
};