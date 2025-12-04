class Solution {
public:
    int binaryGap(int n) {
        int maxGap = 0;
        int lastPos = -1;
        int pos = 0;
        
        while (n > 0) {
            if (n & 1) {  // ตรวจสอบ LSB (Least Significant Bit)
                if (lastPos != -1) {
                    maxGap = max(maxGap, pos - lastPos);
                }
                lastPos = pos;
            }
            pos++;
            n >>= 1;  // shift ขวา 1 bit
        }
        
        return maxGap;
    }
};