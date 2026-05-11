class Solution {
public:
    int minFlips(string target) {
        int count = 0;
        char current = '0';
        
        for (char c : target) {
            if (c != current) {
                count++;
                current = (current == '0') ? '1' : '0';
            }
        }
        
        return count;
    }
};