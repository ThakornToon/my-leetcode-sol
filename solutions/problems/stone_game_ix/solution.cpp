class Solution {
private:
    // จำลองเกมเมื่อ Alice เริ่มด้วย type แรก (1 หรือ 2)
    // return true ถ้า Alice ชนะ, false ถ้า Alice แพ้
    bool simulate(vector<int> mod, int firstType) {
        int n = mod[0] + mod[1] + mod[2];  // จำนวนหินทั้งหมด
        
        // Alice เลือกก้อนแรก
        if (mod[firstType] == 0) return false;
        mod[firstType]--;
        
        int currentSum = firstType;  // ผลรวม modulo 3
        bool isAliceTurn = false;    // false = Bob's turn, true = Alice's turn
        
        for (int move = 1; move < n; move++) {
            // ตรวจสอบว่ามีทางเลือกที่ปลอดภัยหรือไม่
            bool hasSafeMove = false;
            
            if (currentSum == 1) {
                // สถานะ sum=1: การเลือก type1 จะได้ sum=2 (ปลอดภัย)
                //               การเลือก type2 จะได้ sum=0 (อันตราย)
                hasSafeMove = (mod[1] > 0);
            } else { // currentSum == 2
                // สถานะ sum=2: การเลือก type2 จะได้ sum=1 (ปลอดภัย)
                //               การเลือก type1 จะได้ sum=0 (อันตราย)
                hasSafeMove = (mod[2] > 0);
            }
            
            // ถ้ามีทางเลือกที่ปลอดภัย → เลือกทางเลือกนั้น
            if (hasSafeMove) {
                if (currentSum == 1) {
                    mod[1]--;
                    currentSum = 2;
                } else {
                    mod[2]--;
                    currentSum = 1;
                }
            }
            // ถ้าไม่มีทางเลือกที่ปลอดภัย แต่มี type 0 → ใช้ type 0 เพื่อข้ามเทิร์น
            else if (mod[0] > 0) {
                mod[0]--;
                // currentSum ไม่เปลี่ยนแปลง
                isAliceTurn = !isAliceTurn;
                continue;  // ข้ามการสลับเทิร์นด้านล่าง (เราสลับไปแล้ว)
            }
            // ถ้าไม่มีทั้งทางเลือกปลอดภัยและ type 0 → ต้องเลือกหินที่ทำให้แพ้
            else {
                // ผู้เล่นปัจจุบัน (isAliceTurn ? Alice : Bob) เป็นฝ่ายแพ้
                // ถ้าผู้เล่นปัจจุบันคือ Bob → Alice ชนะ
                // ถ้าผู้เล่นปัจจุบันคือ Alice → Alice แพ้
                return !isAliceTurn;
            }
            
            // สลับเทิร์น
            isAliceTurn = !isAliceTurn;
        }
        
        // หมดหินทุกก้อนแล้ว
        // ผู้ที่ต้องเล่นเป็นฝ่ายแพ้ (Bob ชนะอัตโนมัติ)
        return false;
    }
    
public:
    bool stoneGameIX(vector<int>& stones) {
        // นับจำนวนหินแต่ละประเภท (modulo 3)
        vector<int> mod(3, 0);
        for (int stone : stones) {
            int m = stone % 3;
            if (m < 0) m += 3;  // จัดการค่าลบ
            mod[m]++;
        }
        
        // กรณีพิเศษ: ไม่มี type 1 และ type 2 เลย
        if (mod[1] == 0 && mod[2] == 0) {
            return false;  // Alice แพ้แน่นอน
        }
        
        // ลอง Alice เริ่มด้วย type 1 หรือ type 2
        return simulate(mod, 1) || simulate(mod, 2);
    }
};