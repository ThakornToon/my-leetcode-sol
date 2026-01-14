/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     public int f(int x, int y);
 * };
 */

class Solution {
    public List<List<Integer>> findSolution(CustomFunction customfunction, int z) {
        List<List<Integer>> result = new ArrayList<>();
        int x = 1;
        int y = 1000;
        
        while (x <= 1000 && y >= 1) {
            int val = customfunction.f(x, y);
            
            if (val == z) {
                // พบคู่ที่ตรงเงื่อนไข
                List<Integer> pair = new ArrayList<>();
                pair.add(x);
                pair.add(y);
                result.add(pair);
                x++;
                y--;
            } else if (val < z) {
                // ค่าน้อยไป → ต้องเพิ่มค่า → เพิ่ม x
                x++;
            } else {
                // มากไป → ต้องลดค่า → ลด y
                y--;
            }
        }
        
        return result;

    }
}