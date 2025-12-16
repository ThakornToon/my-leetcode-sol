/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* pancakeSort(int* arr, int arrSize, int* returnSize) {
    // จำนวน flips สูงสุดคือ 2*(n-1) ≤ 2*99 = 198 < 10*100
    int* result = (int*)malloc(2 * arrSize * sizeof(int));
    int count = 0;
    
    // ฟังก์ชันพลิก k ตัวแรก
    void flip(int k) {
        result[count++] = k;
        for (int i = 0; i < k / 2; i++) {
            int temp = arr[i];
            arr[i] = arr[k - 1 - i];
            arr[k - 1 - i] = temp;
        }
    }
    
    // filp เริ่มจากใหญ่ไปเล็ก
    for (int target = arrSize; target > 0; target--) {
        // หาตำแหน่งของ target
        int pos = -1;
        for (int i = 0; i < target; i++) {
            if (arr[i] == target) {
                pos = i;
                break;
            }
        }
        
        // ถ้าอยู่ในตำแหน่งที่ถูกต้องแล้ว ข้าม
        if (pos == target - 1) {
            continue;
        }
        
        // พลิกให้ target ไปอยู่ตำแหน่งแรก (ถ้ายังไม่อยู่ที่ตำแหน่ง 0)
        if (pos != 0) {
            flip(pos + 1);
        }
        
        // พลิกให้ target ไปอยู่ตำแหน่งที่ถูกต้อง
        flip(target);
    }
    
    *returnSize = count;
    return result;
}