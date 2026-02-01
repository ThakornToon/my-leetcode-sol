int minimumCost(int* nums, int numsSize) {
    int n = numsSize;
    
    // หาค่าที่น้อยที่สุดและรองน้อยที่สุดในช่วง [1, n-2]
    int min1 = INT_MAX;  // น้อยที่สุด
    int min2 = INT_MAX;  // รองน้อยที่สุด
    
    for (int i = 1; i < n; i++) {
        if (nums[i] < min1) {
            min2 = min1;      // อัปเดตรองน้อยที่สุด
            min1 = nums[i];   // อัปเดตน้อยที่สุด
        } else if (nums[i] < min2) {
            min2 = nums[i];   // อัปเดตรองน้อยที่สุด
        }
    }
    
    return nums[0] + min1 + min2;
}