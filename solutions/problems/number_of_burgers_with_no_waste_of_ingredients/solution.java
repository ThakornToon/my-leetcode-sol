/*
4x + 2y = T
x + y = C

x = (T - 2C) / 2
y = C - x

x ต้องเป็นจำนวนเต็ม ≥ 0
y ต้องเป็นจำนวนเต็ม ≥ 0
*/

class Solution {
    public List<Integer> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        List<Integer> result = new ArrayList<>();
        
        // ตรวจสอบว่า tomatoSlices ต้องเป็นเลขคู่
        if (tomatoSlices % 2 != 0) {
            return result;
        }
        
        int diff = tomatoSlices - 2 * cheeseSlices;
        
        // ตรวจสอบว่า diff เป็นเลขคู่และ >= 0
        if (diff < 0 || diff % 2 != 0) {
            return result;
        }
        
        int jumbo = diff / 2;
        int small = cheeseSlices - jumbo;
        
        // ตรวจสอบว่า small >= 0
        if (small < 0) {
            return result;
        }
        
        // ตรวจสอบความถูกต้องอีกครั้ง
        if (4 * jumbo + 2 * small != tomatoSlices) {
            return result;
        }
        
        result.add(jumbo);
        result.add(small);
        return result;
    }
}