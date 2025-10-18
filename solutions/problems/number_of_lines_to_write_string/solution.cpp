class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int lines = 1;
        int currentWidth = 0;
        
        for (char c : s) {
            int charWidth = widths[c - 'a'];
            
            if (currentWidth + charWidth > 100) {
                lines++;
                currentWidth = charWidth;
            } else {
                currentWidth += charWidth;
            }
        }
        
        return {lines, currentWidth};
    }
};