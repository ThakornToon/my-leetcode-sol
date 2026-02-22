/*
4x + 2y = T
x + y = C

x = (T - 2C) / 2
y = C - x

x ต้องเป็นจำนวนเต็ม ≥ 0
y ต้องเป็นจำนวนเต็ม ≥ 0
*/

class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        // ตรวจสอบว่า tomatoSlices ต้องเป็นเลขคู่
        if (tomatoSlices % 2 != 0) {
            return {};
        }
        
        int diff = tomatoSlices - 2 * cheeseSlices;
        
        // diff ต้องเป็นเลขคู่และ >= 0
        if (diff < 0 || diff % 2 != 0) {
            return {};
        }
        
        int jumbo = diff / 2;
        int small = cheeseSlices - jumbo;
        
        // small ต้อง >= 0
        if (small < 0) {
            return {};
        }
        
        return {jumbo, small};
    }
};