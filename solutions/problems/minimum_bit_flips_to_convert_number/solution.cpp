class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xor_result = start ^ goal;
        int distance = 0;
        
        // นับจำนวนบิต '1' ใน xor_result
        while (xor_result != 0) {
            distance += xor_result & 1; // ตรวจสอบบิตสุดท้าย
            xor_result >>= 1; // เลื่อนบิตไปทางขวา
        }
        
        return distance;
    }
};