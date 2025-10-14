class Solution {
private:
    vector<int> valid_digits = {0, 1, 2, 5, 6, 8, 9};
    int count;
    int max_n;
    
    void generateNumbers(long long current, bool hasGoodDigit) {
        if (current > max_n) return;
        
        if (hasGoodDigit && current > 0) {
            count++;
        }
        
        for (int digit : valid_digits) {
            // หลีกเลี่ยง leading zero
            if (current == 0 && digit == 0) continue;
            
            long long next = current * 10 + digit;
            bool newHasGoodDigit = hasGoodDigit || (digit == 2 || digit == 5 || digit == 6 || digit == 9);
            
            generateNumbers(next, newHasGoodDigit);
        }
    }
    
public:
    int rotatedDigits(int n) {
        count = 0;
        max_n = n;
        generateNumbers(0, false);
        return count;
    }
};