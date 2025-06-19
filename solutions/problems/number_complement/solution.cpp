class Solution {
public:
    int findComplement(int num) {
        if (num == 0) return 1;
    
        long long mask = 1;
        while (mask <= num) {
            mask <<= 1;
        }
        mask -= 1;
        
        return num ^ mask;
    }
};