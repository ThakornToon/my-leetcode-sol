class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        // สูตร: total = numBottles + (numBottles - 1) / (numExchange - 1)
        // ทุกการแลกจะเสียขวดเปล่า (numExchange - 1) ขวด
        // เพราะขวดสุดท้ายที่แลกไม่ได้จะเหลือเป็นขวดเปล่า
        return numBottles + (numBottles - 1) / (numExchange - 1);
    }
};