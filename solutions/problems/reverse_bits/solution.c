uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    for (int i = 0; i < 32; i++) {
        // เลื่อนผลลัพธ์ไปทางซ้าย
        result <<= 1;
        // เพิ่มบิตสุดท้ายของ n เข้าไปในผลลัพธ์
        result |= (n & 1);
        // เลื่อน n ไปทางขวา
        n >>= 1;
    }
    return result;
}