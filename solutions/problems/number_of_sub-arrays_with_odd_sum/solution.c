#define MOD 1000000007
int numOfSubarrays(int* arr, int arrSize) {
    long long oddCount = 0;   // จำนวน prefix sum ที่เป็นคี่
    long long evenCount = 1;  // จำนวน prefix sum ที่เป็นคู่ (เริ่มต้น prefix[0] = 0 ถือเป็นคู่)
    long long prefixSum = 0;
    long long result = 0;
    
    for (int i = 0; i < arrSize; i++) {
        prefixSum += arr[i];
        
        if (prefixSum % 2 == 1) {
            // prefix ปัจจุบันเป็นคี่
            // subarray ที่ลงท้ายด้วย i และผลรวมเป็นคี่ = evenCount
            result = (result + evenCount) % MOD;
            oddCount++;
        } else {
            // prefix ปัจจุบันเป็นคู่
            // subarray ที่ลงท้ายด้วย i และผลรวมเป็นคี่ = oddCount
            result = (result + oddCount) % MOD;
            evenCount++;
        }
    }
    
    return (int)result;
}