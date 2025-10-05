class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        int bitsSize = bits.size();
    
        while (i < bitsSize - 1) {
            if (bits[i] == 1) {
                i += 2; // Skip 2-bit character
            } else {
                i += 1; // Skip 1-bit character
            }
        }
        
        return i == bitsSize - 1;
    }
};