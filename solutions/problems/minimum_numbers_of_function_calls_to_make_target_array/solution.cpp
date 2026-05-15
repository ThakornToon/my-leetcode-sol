class Solution {
public:
    int minOperations(vector<int>& nums) {
        int operations = 0;  // ต้อง -1 กี่ครั้ง
        int maxBit = 0;  // ต้องหาร 2 มากสุดกี่ครั้ง
        
        for (int num : nums) {
            int bitPos = 0;  // ตำแหน่งบิต 1 ที่อยู่ซ้ายสุด(จำนวนครั้งที่หาร 2)
            while (num > 0) {
                if (num & 1) {  // ต้องลบ 1
                    operations++;
                    num -= 1;
                } else {
                    bitPos++;  // หาร 2 
                    num >>= 1;
                }
            }
            
            maxBit = max(maxBit, bitPos);
        }
        
        return operations + maxBit;
    }
};
