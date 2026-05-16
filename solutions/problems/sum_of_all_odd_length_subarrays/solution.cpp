class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int total = 0;
        
        for (int i = 0; i < n; i++) {
            // จำนวน subarray ที่ arr[i] ปรากฏ
            int left = i + 1;      // ตัวเลือกทางซ้าย (รวม i)
            int right = n - i;      // ตัวเลือกทางขวา (รวม i)
            
            // จำนวน subarray ทั้งหมดที่มี arr[i]
            long long totalSubarrays = (long long)left * right;
            
            // จำนวน subarray ความยาวคี่ที่มี arr[i]
            // สูตร: ceil(totalSubarrays / 2)
            long long oddSubarrays = (totalSubarrays + 1) / 2;
            
            total += arr[i] * oddSubarrays;
        }
        
        return total;
    }
};