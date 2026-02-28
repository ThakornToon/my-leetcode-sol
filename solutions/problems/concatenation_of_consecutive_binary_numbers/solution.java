class Solution {
    public int concatenatedBinary(int n) {
        long result = 0;  
        int length = 0; // ความยาว binary ของตัวเลขปัจจุบัน
        
        for (int i = 1; i <= n; i++) {
            // ถ้า i เป็นเลขยกกำลังสอง ความยาว binary จะเพิ่มขึ้น 1
            // เช่น 1 (1), 2 (10), 4 (100), 8 (1000)
            if ((i & (i - 1)) == 0) {
                length++;
            }
            
            result = ((result << length) | i) % 1000000007;
        }
        
        return (int)result;
    }
}