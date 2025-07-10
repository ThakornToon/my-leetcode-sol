class Solution {
public:
    int hammingDistance(int x, int y) {
        int xor_result = x ^ y;
        int distance = 0;
        
        // นับจำนวนบิต '1' ใน xor_result
        while (xor_result != 0) {
            distance += xor_result & 1; // ตรวจสอบบิตสุดท้าย
            xor_result >>= 1; // เลื่อนบิตไปทางขวา
        }
        
        return distance;
    }
};