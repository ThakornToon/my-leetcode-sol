/* 
#include <uthash.h> ใช้ library สำหรับ hash map
- สร้าง hash table จาก struct ปกติของ C
- ใช้ macro พิเศษในการจัดการ
เพิ่มข้อมูล: HASH_ADD
ค้นหาข้อมูล: HASH_FIND
ลบข้อมูล: HASH_DEL
วนลูปผ่านข้อมูล: HASH_ITER
นับจำนวนข้อมูล: HASH_COUNT

HASH_ADD_INT - สำหรับ key แบบ integer
HASH_ADD_STR - สำหรับ key แบบ string
HASH_ADD_PTR - สำหรับ key แบบ pointer
HASH_ADD - สำหรับ key ขนาดใดๆ

ต้อง malloc ก่อนเพิ่มข้อมูล
ต้อง free หลังลบข้อมูล
*/

struct hashMap {
    int key;        // เก็บค่าผลรวม
    int value;      // เก็บจำนวนครั้งที่ผลรวมนี้ปรากฏ
    UT_hash_handle hh;  // ฟิลด์พิเศษสำหรับใช้กับ uthash
};

int fourSumCount(int* nums1, int nums1Size, int* nums2, int nums2Size, int* nums3, int nums3Size, int* nums4, int nums4Size) {
    struct hashMap* map = NULL; // ต้องเริ่มต้นด้วย NULL
    int count = 0;

    // คำนวณผลรวมจาก nums1 และ nums2
    for (int i = 0; i < nums1Size; i++) {
        for (int j = 0; j < nums2Size; j++) {
            int sum = nums1[i] + nums2[j]; // key
            struct hashMap* entry;
            HASH_FIND_INT(map, &sum, entry); // หา sum ใน map ถ้าพบจะใช้ entry ชี้ไป
            if (entry == NULL) {
                entry = (struct hashMap*)malloc(sizeof(struct hashMap));
                entry->key = sum;
                entry->value = 1;
                HASH_ADD_INT(map, key, entry); // เพิ่ม entry ลงใน map
            } else {
                entry->value++;
            }
        }
    }

    // ตรวจสอบผลรวมจาก nums3 และ nums4
    for (int i = 0; i < nums3Size; i++) {
        for (int j = 0; j < nums4Size; j++) {
            int target = -(nums3[i] + nums4[j]);
            struct hashMap* entry;
            HASH_FIND_INT(map, &target, entry);
            if (entry != NULL) {
                count += entry->value;
            }
        }
    }

    // ล้าง memory
    struct hashMap* current; // ใช้ชี้ไปยัง entry ปัจจุบันที่กำลังประมวลผล
    struct hashMap* tmp; // ใช้เก็บ pointer ชั่วคราวเพื่อป้องกันการสูญเสียข้อมูลขณะลบ
    HASH_ITER(hh, map, current, tmp) {  
        HASH_DEL(map, current); // ลบ current ที่อยู่ใน map แต่ยังไม่คืน memory
        free(current); 
    }
    //การใช้ tmp มีความสำคัญเพราะ: เมื่อลบ current ออกจาก hash table แล้ว เราอาจไม่สามารถเข้าถึง entry ถัดไปได้, tmp เก็บ pointer ของ entry ถัดไปไว้ก่อนลบ entry ปัจจุบัน
    return count;
}