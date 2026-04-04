class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int len = encodedText.length();
        int cols = len / rows;
        
        string result;
        
        // อ่านแนวทแยง
        for (int startCol = 0; startCol < cols; startCol++) {
            for (int r = 0, c = startCol; r < rows && c < cols; r++, c++) {
                result += encodedText[r * cols + c];
            }
        }
        
        // ตัดช่องว่างท้าย
        while (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }
        
        return result;
    }
};