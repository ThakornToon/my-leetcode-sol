class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int n = nums.size();
        
        // ถ้าจำนวนตัวเลขเป็นเลขคู่ → Alice ชนะเสมอ
        if (n % 2 == 0) {
            return true;
        }
        
        // คำนวณ XOR ทั้งหมด
        int totalXor = 0;
        for (int num : nums) {
            totalXor ^= num;
        }
        
        // ถ้า XOR ทั้งหมด == 0 → Alice ชนะ
        // มิฉะนั้น (n คี่ และ XOR != 0) → Alice แพ้

        // XOR ทั้งหมด != 0 หมายความว่ามีอย่างน้อย 1 bit ที่เป็น 1 เป็นจำนวนคี่ครั้ง
        // n เป็นคู่สามารถเลือกตัวที่ทำให้ XOR != 0 ได้อยู่
        // n เป็นคี่ ณ จุดหนึ่งสุดท้ายจะมีอย่างน้อย 1 bit ที่เป็น 1 มีจำนวนเท่ากับ n และเมื่อเลืออกออก XOR == 0 
        return totalXor == 0;
    }
};