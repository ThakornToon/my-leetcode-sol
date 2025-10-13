int maxChunksToSorted(int* arr, int arrSize) {
    int sum = 0;
    int expected_sum = 0;
    int chunks = 0;
    
    for (int i = 0; i < arrSize; i++) {
        sum += arr[i];
        expected_sum += i;
        
        // ถ้าผลรวมเท่ากัน แสดงว่าแบ่ง chunk ได้
        if (sum == expected_sum) {
            chunks++;
        }
    }
    
    return chunks;
}