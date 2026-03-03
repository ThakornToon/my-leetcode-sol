long long calculateSum(int* nums, int numsSize, int divisor) {
    long long sum = 0;
    for (int i = 0; i < numsSize; i++) {
        // การหารแบบปัดเศษขึ้น: (num + divisor - 1) / divisor
        sum += (nums[i] + divisor - 1) / divisor;
    }
    return sum;
}

int smallestDivisor(int* nums, int numsSize, int threshold) {
    
    int max = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
    }
    
    int left = 1;
    int right = max;
    int result = right;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        long long sum = calculateSum(nums, numsSize, mid);
        
        if (sum <= threshold) {
            // ถ้าผลรวม <= threshold ลอง divisor ที่น้อยลง
            result = mid;
            right = mid - 1;
        } else {
            // ถ้าผลรวม > threshold ต้องใช้ divisor ที่มากขึ้น
            left = mid + 1;
        }
    }
    
    return result;
}