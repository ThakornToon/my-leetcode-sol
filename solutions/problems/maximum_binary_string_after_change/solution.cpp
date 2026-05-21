class Solution {
public:
    string maximumBinaryString(string binary) {
        // ถ้ามี 0 อยู่ > 1 ตัว สามารถเปลี่ยนให้เหลือ 0 เพียง 1 ตัวได้ 
        // โดยเลื่อน 1 ทั้งหมดไปทางขวา แล้วรวม 0 เข้าด้วยกัน (กับ 0 ตัวแรกจากทางซ้าย)
        int n = binary.length();
        int firstZero = -1;
        int zeroCount = 0;
        
        // หาตำแหน่ง 0 ตัวแรกและนับจำนวน 0
        for (int i = 0; i < n; i++) {
            if (binary[i] == '0') {
                if (firstZero == -1) firstZero = i;
                zeroCount++;
            }
        }
        
        // ถ้าไม่มี 0 หรือมี 0 แค่ตัวเดียว -> คืนค่าเดิม
        if (zeroCount <= 1) return binary;
        
        // สร้างผลลัพธ์: 1 ทั้งหมด ยกเว้นตำแหน่ง firstZero + zeroCount - 1 ที่เป็น 0 (0 ตัวสุดท้ายอยู่หลังกลุ่ม 0)
        string result(n, '1');
        result[firstZero + zeroCount - 1] = '0';
        
        return result;
    }
};