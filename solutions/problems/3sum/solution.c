/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

 int cmp(const void *a,const void *b) { //void* เป็น pointer ประเภททั่วไปที่ชี้ไปที่ข้อมูลชนิดใดก็ได้
    return *((int*) a) - *((int*) b); //แปลงเป็น int* เพื่อเปรียบเทียบค่าจากนั้น return int ไปที่ qsort ถ้า <0 a ควรอยู่ก่อน b แต่ถ้า >0 a ควรอยู่หลัง b
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmp);
    (*returnSize) = 0; //ตัวไล่ index ซึ่งสุดท้ายจะเป็นจำนวนของคำตอบ
    (*returnColumnSizes) = (int*) malloc(sizeof(int) * numsSize * numsSize); //deref pointer ที่ซ้อน pointer เพื่อเขียน adress ลงไปโดยจองพื้นที่สำหรับเก็บ int จำนวน numsSize^2 เผื่อไว้เหลือๆ (returnColumnSizes เป็นอาเรย์หนึ่งมิติที่ใช้ doule pointer ในพารามิเตอร์เป็นการ pass by reference เพื่อให้แก้ไข pointer ได้ ไม่จำเป็นต้องเป็นอาเรย์สองมิติเสมอไป)
    //ตัว **returnColumnSizes ถูกใช้เพื่อส่งกลับ array จำนวน column ซึ่งก็คือ 3 สำหรับทุก sub array 
    int **ret = (int**) malloc(sizeof(int*) * numsSize * numsSize); //จองพื้นที่เก็บ pointer ที่ชี้ไป array ขนาด 3 โดยเผื่อพื้นที่ไว้เช่นกันสำหรับ array คำตอบ
    //นึกภาพว่า ret เป็นอาเรย์สองมิติ อันนี้กำหนดขนาดของมิติที่สองไว้ ่ส่วนมิติแรกจะไปกำหนดขนาดในส่วนด้านล่าง

    for (int i = 0; i < numsSize - 2; i++) {
        if (i == 0 || nums[i] != nums[i-1]) {
            int l = i + 1;
            int r = numsSize - 1;
            while (l < r) {
                if (nums[i] + nums[l] + nums[r] < 0) {
                    l++;
                } else if (nums[i] + nums[l] + nums[r] > 0) {
                    r--;
                } else {
                    ret[(*returnSize)] = (int*) malloc(sizeof(int) * 3); //ชนาดของแต่ละ array คำตอบซึ่งเก็บ int สามตัว
                    (*returnColumnSizes)[(*returnSize)] = 3;
                    ret[(*returnSize)][0] = nums[i];
                    ret[(*returnSize)][1] = nums[l];
                    ret[(*returnSize)][2] = nums[r];
                    (*returnSize)++; //ไล่ไปเรื่อยๆ 0, 1, 2, ...
                    l++;
                    while (l < r && nums[l] == nums[l-1]){
                        l++;
                    }
                }
            }
        }
    }
    return ret;
}