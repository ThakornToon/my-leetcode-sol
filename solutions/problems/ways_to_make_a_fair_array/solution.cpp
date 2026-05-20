class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixEven(n + 1, 0), prefixOdd(n + 1, 0);
        
        // คำนวณ prefix sums ถึง i (ไม่รวม index i)
        for (int i = 0; i < n; i++) {
            prefixEven[i + 1] = prefixEven[i];
            prefixOdd[i + 1] = prefixOdd[i];
            if (i % 2 == 0) {
                prefixEven[i + 1] += nums[i];
            } else {
                prefixOdd[i + 1] += nums[i];
            }
        }
        
        int result = 0;
        
        for (int i = 0; i < n; i++) {
            // ฝั่งซ้ายตำแหน่งไม่เปลี่ยน
            int leftEven = prefixEven[i];
            int leftOdd = prefixOdd[i];
            
            // สลับคู่คี่ในฝั่งขวา(ไม่สนใจ index i เดิม)
            int totalEven = prefixEven[n] - prefixEven[i + 1];
            int totalOdd = prefixOdd[n] - prefixOdd[i + 1];
            
            int rightEven, rightOdd;
            // หลังจากลบ i แล้ว parity ของ index ที่เหลือจะสลับกัน
            rightEven = totalOdd;
            rightOdd = totalEven;
            
            if (leftEven + rightEven == leftOdd + rightOdd) {
                result++;
            }
        }
        
        return result;
    }
};