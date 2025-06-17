/*
การ XOR สลับที่กันได้ โดยถ้า x^x = 0 ทำให้พอ XOR ทั้งหมดจะเหลือแค่สองตัว x ^ y ที่จะไม่หักล้างกันหมด มีอย่างน้อยหนึ่งบิตที่แตกต่าง 
เราจำแนกตัวเลขเป็นสองกลุ่มโดยดูตำแหน่งบิตที่แตกต่าง (XOR เป็น 1) ใช้แค่หนึ่งตำแหน่งก็พอ
2, 2, 3, 5, 4, 4 
2 - 010
3 - 011
4 - 100
5 - 101
XOR ทั้งหมดได้ 3 ^ 5 = 110 จะแบ่งตัวเป็นเป็นสองกลุ่มคือตำแหน่งที่สองเป็น 1 หรือ 0 (010, 000) นำเลขที่ประเภทตรงกันมา XOR กันเอง
กลุ่ม 1 - 2, 2, 3
กลุ่ม 2 - 4, 4, 5
*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int overall_xor = 0;
        for (int n : nums) {
            overall_xor ^= n;
        }

        int first_group_xor = 0;
        int second_group_xor = 0;

        int bit_pos_dif = 0;
        while (((overall_xor >> bit_pos_dif) & 1) != 1) {
            bit_pos_dif++;
        }

        for (int num : nums) {
            if (((num >> bit_pos_dif) & 1) == 1) {
                first_group_xor ^= num;
            } else {
                second_group_xor ^= num;
            }
        }

        return {first_group_xor, second_group_xor};
    }
};