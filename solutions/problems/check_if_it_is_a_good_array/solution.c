int gcd(int a, int b) {
    // Euclidean algorithm
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    
    return a;
}

bool isGoodArray(int* nums, int numsSize) {
    // gcd(a, b, c) = gcd(gcd(a, b), c) = gcd(a, gcd(b, c))
    // หา gcd ของทุกตัวใน nums
    int currentGcd = nums[0];
    
    for (int i = 1; i < numsSize; i++) {
        currentGcd = gcd(currentGcd, nums[i]);
        
        // Optimization: ถ้า gcd เป็น 1 แล้ว ให้หยุดเลย
        if (currentGcd == 1) {
            return true;
        }
    }
    
    return currentGcd == 1;
}