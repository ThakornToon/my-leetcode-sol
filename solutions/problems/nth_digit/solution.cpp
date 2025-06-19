class Solution {
public:
    int findNthDigit(int n) {
        long long num = n;
        int digits = 1;      // จำนวนหลักปัจจุบัน
        long long count = 9; // จำนวนตัวเลขในกลุ่ม digits หลัก
        long long start = 1; // ตัวเลขเริ่มต้นของกลุ่ม
        
        // ขั้นตอนที่ 1: หาจำนวนหลักของตัวเลขที่ n อยู่
        while (num > digits * count) {
            num -= digits * count;
            digits++;
            count *= 10;
            start *= 10;
        }
        
        // ขั้นตอนที่ 2: หาตัวเลขที่เฉพาะเจาะจง
        long long number = start + (num - 1) / digits;
        int digit_index = (num - 1) % digits;
        
        // ขั้นตอนที่ 3: หาตัวเลขที่ต้องการ
        return to_string(number)[digit_index] - '0';
    }
};