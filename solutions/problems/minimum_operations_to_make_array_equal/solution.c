int minOperations(int n) {
    // จำนวน operation = ผลรวมของ (n - (2i+1)) สำหรับ i < n/2
    // = (n/2) * ((n+1)/2)
    return (n / 2) * ((n + 1) / 2);
}