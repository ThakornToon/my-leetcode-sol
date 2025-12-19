int numPairsDivisibleBy60(int* time, int timeSize) {
    int count[60] = {0};
    int pairs = 0;
    
    for (int i = 0; i < timeSize; i++) {
        int rem = time[i] % 60;
        
        // คำนวณ complement (ตัวที่บวกกันได้ 60 หรือ 0)
        int complement = (60 - rem) % 60;
        
        // คู่กับตัวที่มี complement ที่มาก่อนหน้า
        pairs += count[complement];
        
        // เพิ่มจำนวนใน count
        count[rem]++;
    }
    
    return pairs;
}