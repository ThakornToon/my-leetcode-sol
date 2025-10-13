/*
Parent ที่ตำแหน่ง p สร้าง:
Left child ที่ตำแหน่ง 2p-1
Right child ที่ตำแหน่ง 2p

การหา Parent:
ถ้า k เป็นคี่ (left child): parent = (k+1)/2
ถ้า k เป็นคู่ (right child): parent = k/2

สังเกตว่า:
Left child (k คี่): ได้ค่าเดียวกับ parent → ไม่ flip
Right child (k คู่): ได้ค่าตรงข้ามกับ parent → flip 1 ครั้ง
*/

class Solution {
public:
    int kthGrammar(int n, int k) {
        int flip = 0;
        k--; // Change to 0-indexed
        
        while (k > 0) {
            if (k % 2 == 1) {
                flip++;
            }
            k /= 2;
        }
        
        return flip % 2;
    }
};