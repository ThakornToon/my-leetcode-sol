class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        vector<int> result(n, 0);
        
        // Left to Right Pass
        int balls = 0;
        int operations = 0;
        
        for (int i = 0; i < n; i++) {
            result[i] = operations;
            if (boxes[i] == '1') balls++;
            operations += balls;
        }
        
        // Right to Left Pass
        balls = 0;
        operations = 0;
        
        for (int i = n - 1; i >= 0; i--) {
            result[i] += operations;
            if (boxes[i] == '1') balls++;
            operations += balls;
        }
        
        return result;
    }
};