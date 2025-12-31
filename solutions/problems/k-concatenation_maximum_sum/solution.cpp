class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        
        if (n == 0) return 0;
        
        // กรณี k == 1
        if (k == 1) {
            return kadane(arr) % MOD;
        }
        
        // หาผลรวมทั้งหมด
        long long totalSum = 0;
        for (int num : arr) totalSum += num;
        
        // สร้าง array 2 สำเนา
        vector<int> twoCopies;
        twoCopies.insert(twoCopies.end(), arr.begin(), arr.end());
        twoCopies.insert(twoCopies.end(), arr.begin(), arr.end());
        
        long long kadaneTwo = kadane(twoCopies);
        
        // คำนวณผลลัพธ์ที่ถูกต้อง
        long long result = kadaneTwo;  // กรณี 2 สำเนา
        
        // ถ้า totalSum > 0 และ k > 2
        if (totalSum > 0 && k > 2) {
            // ต้องหา maxPrefix และ maxSuffix
            long long maxPrefix = 0, prefixSum = 0;
            long long maxSuffix = 0, suffixSum = 0;
            
            // หา maxPrefix
            for (int num : arr) {
                prefixSum += num;
                maxPrefix = max(maxPrefix, prefixSum);
            }
            
            // หา maxSuffix
            for (int i = n - 1; i >= 0; i--) {
                suffixSum += arr[i];
                maxSuffix = max(maxSuffix, suffixSum);
            }
            
            // กรณีใช้ k สำเนา: maxPrefix + maxSuffix + (k-2)*totalSum
            result = max(result, maxPrefix + maxSuffix + (k - 2) * totalSum);
        }
        
        return max(0LL, result) % MOD;
    }
private:
    long long kadane(vector<int>& arr) {
        long long maxEndingHere = 0;
        long long maxSoFar = 0;
        
        for (int num : arr) {
            maxEndingHere = max((long long)num, maxEndingHere + num);
            maxSoFar = max(maxSoFar, maxEndingHere);
        }
        
        return maxSoFar;
    }
};