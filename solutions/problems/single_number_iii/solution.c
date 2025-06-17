/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize) {
    long long xorAll = 0;
    for (int i = 0; i < numsSize; i++) {
        xorAll ^= nums[i];
    }

    long long setBit = xorAll & -xorAll; // ได้บิต 1 ที่ตำแหน่งแรกจากทางขวาเท่านั้น
    int a = 0, b = 0;
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] & setBit) {
            a ^= nums[i];
        } else {
            b ^= nums[i];
        }
    }

    int* result = (int*)malloc(2 * sizeof(int));
    result[0] = a;
    result[1] = b;
    *returnSize = 2;
    return result;
}
/*
การ XOR สลับที่กันได้ โดยถ้า x^x = 0 ทำให้พอ XOR ทั้งหมดจะเหลือแค่สองตัว x ^ y ที่จะไม่หักล้างกันหมด (มีอย่างน้อยหนึ่งบิตที่แตกต่าง) 
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