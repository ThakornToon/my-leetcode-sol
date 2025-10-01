class Solution {
public:
    bool checkValidString(string s) {
        int min_open = 0;  // Minimum possible open parentheses
        int max_open = 0;  // Maximum possible open parentheses
        
        for (char c : s) {
            if (c == '(') {
                min_open++;
                max_open++;
            } else if (c == ')') {
                min_open--;
                max_open--;
            } else { // c == '*'
                min_open--;
                max_open++;
            }
            
            // If max_open < 0, too many ')'
            if (max_open < 0) return false;
            
            // min_open cannot be negative (we can always choose '*' as empty)
            min_open = max(min_open, 0);
        }
        
        return min_open == 0;
    }
};