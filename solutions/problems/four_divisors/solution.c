int sumFourDivisors(int* nums, int numsSize) {
    int total = 0;
    
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        int firstDivisor = 0;  // ตัวหารตัวแรกที่ไม่ใช่ 1
        
        // หาจนถึง sqrt(num)
        for (int d = 2; d * d <= num; d++) {
            if (num % d == 0) {
                if (firstDivisor == 0) {
                    firstDivisor = d;
                } else {
                    // มีตัวหารมากกว่า 1 คู่ → เกิน 4 ตัว
                    firstDivisor = -1;
                    break;
                }
            }
        }
        
        if (firstDivisor > 0 && firstDivisor != num / firstDivisor) {
            // มีตัวหารแค่ 1 คู่ และไม่ใช่ sqrt(num)
            total += 1 + num + firstDivisor + (num / firstDivisor);
        }
    }
    
    return total;
}