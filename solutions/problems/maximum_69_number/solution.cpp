class Solution {
public:
    int maximum69Number (int num) {
        int numCopy = num;
        int pos = -1;
        int i = 0;
        
        while (numCopy > 0) {
            if (numCopy % 10 == 6) {
                pos = i;
            }
            numCopy /= 10;
            i++;
        }
        
        return (pos == -1) ? num : num + 3 * pow(10, pos);
    }
};