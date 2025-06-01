class Solution {
public:
    int titleToNumber(string columnTitle) {
        int i, result = 0;
        for (i = 0; i < columnTitle.size(); i++) {
            result = result * 26 + (columnTitle[i] - 'A' + 1);
        }
        return result;
    }
};