/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxValue(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* ans = (int*)malloc(numsSize * sizeof(int));
    
    if (numsSize == 0) return ans;
    
    // ค่าสูงสุดทางซ้าย (ซ้าย → ขวา) โดดย้อนไปหาค่าที่มากสุด
    ans[0] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        // ans[i] = max(ค่าสูงสุดก่อนหน้า, ค่าปัจจุบัน)
        ans[i] = (ans[i-1] > nums[i]) ? ans[i-1] : nums[i];
    }
    
    // ค่าน้อยสุดทางขวา (ขวา → ซ้าย)
    int suffixMin = INT_MAX;
    for (int i = numsSize - 1; i >= 0; i--) {
        // ถ้าค่าสูงสุดที่ย้อนได้ (จากซ้าย) มากกว่าค่าต่ำสุดทางขวา
        // แสดงว่าสามารถกระโดดขวาไปหาค่าสูงสุดที่ไกลออกไปได้
        // โดดไปค่ามากสุดทางซ้ายแล้วโดดมาค่าน้อยสุดทางขวาจะโดดถอยมาที่ i+1 ได้เสมอ
        if (ans[i] > suffixMin) {
            // กระโดดขวา → ได้ค่าสูงสุดเท่ากับ ans[i+1]
            ans[i] = ans[i + 1];
        }
        // อัปเดตค่าต่ำสุดทางขวา (รวม nums[i] ด้วย)
        suffixMin = (suffixMin < nums[i]) ? suffixMin : nums[i];
    }
    
    return ans;
}