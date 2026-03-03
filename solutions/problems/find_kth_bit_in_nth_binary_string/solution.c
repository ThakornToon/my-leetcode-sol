char findKthBit(int n, int k) {
    // Base Case
    if (n == 1) {
        return '0';
    }
    
    // หาความยาวของ Sn
    int length = (1 << n) - 1;  // 2^n - 1
    int mid = length / 2 + 1;   // ตำแหน่งตรงกลาง
    
    if (k == mid) {
        return '1';  // ตรงกลางเป็น '1' เสมอ
    }
    else if (k < mid) {
        // อยู่ในส่วนแรก (Sn-1)
        return findKthBit(n - 1, k);
    }
    else {
        // อยู่ในส่วนท้าย
        // หาตำแหน่งที่สมมาตรใน Sn-1
        int newK = length - k + 1;
        char bit = findKthBit(n - 1, newK);
        // invert ค่า
        return (bit == '0') ? '1' : '0';
    }
}