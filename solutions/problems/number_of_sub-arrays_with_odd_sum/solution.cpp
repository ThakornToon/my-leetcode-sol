class Solution {
private:
    const int MOD = 1000000007;
    
public:
    int numOfSubarrays(vector<int>& arr) {
         int odd = 0;   // จำนวน subarray ที่ลงท้ายด้วยตำแหน่งปัจจุบันและมีผลรวมคี่
        int even = 0;  // จำนวน subarray ที่ลงท้ายด้วยตำแหน่งปัจจุบันและมีผลรวมคู่
        int result = 0;
        
        for (int num : arr) {
            if (num % 2 == 1) {
                // ถ้า num เป็นคี่
                // subarray ใหม่ที่ลงท้ายด้วยตำแหน่งนี้:
                // - ตัวเดียว (num) → คี่
                // - ต่อกับ subarray เดิมที่มีผลรวมคู่ → คี่
                int newOdd = 1 + even;
                int newEven = odd;
                odd = newOdd;
                even = newEven;
            } else {
                // ถ้า num เป็นคู่
                // subarray ใหม่ที่ลงท้ายด้วยตำแหน่งนี้:
                // - ตัวเดียว (num) → คู่
                // - ต่อกับ subarray เดิมที่มีผลรวมคี่ → คี่
                int newOdd = odd;
                int newEven = 1 + even;
                odd = newOdd;
                even = newEven;
            }
            result = (result + odd) % MOD;
        }
        
        return result;
    }
};