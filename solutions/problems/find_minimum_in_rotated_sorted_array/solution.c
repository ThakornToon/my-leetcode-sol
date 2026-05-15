int findMin(int* nums, int numsSize) {
    int left = 0;
    int right = numsSize - 1;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        // ถ้า mid > right แสดงว่า minimum อยู่ในครึ่งขวา
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } 
        // ถ้า mid <= right แสดงว่า minimum อยู่ในครึ่งซ้าย (รวม mid)
        else {
            right = mid;
        }
    }
    
    return nums[left];
}