/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

// โครงสร้างสำหรับเก็บค่าและ index ของ nums2
typedef struct {
    int value;
    int index;
} Pair;

// value น้อยไปมาก
int comparePair(const void* a, const void* b) {
    return ((Pair*)a)->value - ((Pair*)b)->value;
}

int* advantageCount(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    *returnSize = nums1Size;
    
    // สร้าง array สำหรับเก็บผลลัพธ์
    int* result = (int*)malloc(nums1Size * sizeof(int));
    
    // Sort nums1
    qsort(nums1, nums1Size, sizeof(int), compare);
    
    // สร้าง array ของ pairs สำหรับ nums2 (เก็บค่าและ index)
    Pair* pairs = (Pair*)malloc(nums2Size * sizeof(Pair));
    for (int i = 0; i < nums2Size; i++) {
        pairs[i].value = nums2[i];
        pairs[i].index = i;
    }
    qsort(pairs, nums2Size, sizeof(Pair), comparePair);
    
    // สองพอยน์เตอร์
    int left = 0;
    int right = nums1Size - 1;
    
    // ไล่จากค่าที่ใหญ่ที่สุดใน nums2 (ไล่จากหลังมาหน้า)
    for (int i = nums2Size - 1; i >= 0; i--) {
        int target = pairs[i].value;
        int idx = pairs[i].index;
        
        if (nums1[right] > target) {
            // ใช้ตัวที่ใหญ่ที่สุดที่ชนะได้
            result[idx] = nums1[right];
            right--;
        } else {
            // ใช้ตัวที่เล็กที่สุด
            result[idx] = nums1[left];
            left++;
        }
    }
    
    // คืนหน่วยความจำ
    free(pairs);
    
    return result;
}