class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        int total = 10; // สำหรับ 1 หลัก
        int uniqueDigits = 9;
        int availableNumbers = 9;
        
        for (int i = 2; i <= n; ++i) {
            uniqueDigits *= availableNumbers;
            total += uniqueDigits;
            availableNumbers--;
        }
        
        return total;
    }
};