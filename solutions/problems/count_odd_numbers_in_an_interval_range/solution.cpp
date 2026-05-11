class Solution {
public:
    int countOdds(int low, int high) {
        int count = (high - low) / 2;
    
        // ถ้า low เป็นคี่ หรือ high เป็นคี่ ให้บวก 1
        if (low % 2 == 1 || high % 2 == 1) {
            count++;
        }
        
        return count;
    }
};