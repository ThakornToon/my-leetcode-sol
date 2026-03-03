class Solution {
public:
    char findKthBit(int n, int k) {
        bool invert = false;
        
        // ไล่จาก n ลงมา
        for (int i = n; i > 1; i--) {
            int length = (1 << i) - 1;  // 2^i - 1
            int mid = length / 2 + 1;
            
            if (k == mid) {
                // ตรงกลาง: ถ้า invert == true -> '0', else -> '1'
                return invert ? '0' : '1';
            } else if (k > mid) {
                // อยู่ในส่วนท้าย: ต้อง invert และ mirror
                k = length - k + 1;
                invert = !invert;
            }
            // ถ้า k < mid: อยู่ในส่วนแรก ไม่ต้องทำอะไร
        }
        
        // n == 1
        return invert ? '1' : '0';
    }
};