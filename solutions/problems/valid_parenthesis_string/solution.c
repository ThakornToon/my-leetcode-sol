bool checkValidString(char* s) {
    int n = strlen(s);
    int min_open = 0;  // Minimum possible open parentheses
    int max_open = 0;  // Maximum possible open parentheses
        
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            min_open++;
            max_open++;
        } else if (s[i] == ')') {
            min_open--;
            max_open--;
        } else { // s[i] == '*'
            min_open--; // *->)
            max_open++; // *->(
        }
            
        // If max_open < 0, too many ')'
        if (max_open < 0) return false;
        
        // min_open cannot be negative (we can always choose '*' as empty)
        if (min_open < 0) min_open = 0;
    }
        
    return min_open == 0;
}