class Solution {
public:
    string interpret(string command) {
        string result;
        int n = command.length();
        
        for (int i = 0; i < n; i++) {
            if (command[i] == 'G') {
                result += 'G';
            }
            else if (command[i] == '(') {
                if (command[i + 1] == ')') {
                    result += 'o';
                    i++; // ข้าม ')'
                }
                else {
                    result += "al";
                    i += 3; // ข้าม "al)"
                }
            }
        }
        
        return result;
    }
};