/*
ใน array ที่เป็น permutation ของ [0, 1, 2, ..., n-1]:
ตำแหน่งที่ถูกต้อง ของค่า x ควรอยู่ที่ index x
Local inversion เกิดขึ้นได้เฉพาะระหว่าง element ที่อยู่ติดกันเท่านั้น
Global inversion เกิดขึ้นเมื่อมี element ที่อยู่ห่างกัน

จากเงื่ออนไขจะพบว่า
แต่ละ element สามารถเคลื่อนที่จากตำแหน่งเดิมได้ ไม่เกิน 1 ตำแหน่ง
เพราะถ้าเคลื่อนที่เกิน 1 ตำแหน่ง จะเกิด global inversion เพิ่มเติม
*/

class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (abs(nums[i] - i) > 1) {
                return false;
            }
        }
        return true;
    }
};