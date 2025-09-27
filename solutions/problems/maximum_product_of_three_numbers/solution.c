int maximumProduct(int* nums, int numsSize) {
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
    int min1 = INT_MAX, min2 = INT_MAX;
    
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        
        // อัปเดตสามค่ามากที่สุด
        if (num > max1) {
            max3 = max2;
            max2 = max1;
            max1 = num;
        } else if (num > max2) {
            max3 = max2;
            max2 = num;
        } else if (num > max3) {
            max3 = num;
        }
        
        // อัปเดตสองค่าน้อยที่สุด
        if (num < min1) {
            min2 = min1;
            min1 = num;
        } else if (num < min2) {
            min2 = num;
        }
    }
    
    // เปรียบเทียบสองกรณี
    int product1 = max1 * max2 * max3;  // สามค่าบวกใหญ่ที่สุด
    int product2 = min1 * min2 * max1;  // สองค่าลบและค่าบวกใหญ่ที่สุด
    
    return (product1 > product2) ? product1 : product2;
}