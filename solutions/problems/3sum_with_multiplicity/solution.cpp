class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        const int MOD = 1e9 + 7;
        const int MAX_VAL = 100;
        
        vector<long long> count(MAX_VAL + 1, 0);
        // นับความถี่
        for (int num : arr) {
            count[num]++;
        }
        
        long long result = 0;
        
        // ลูปผ่านค่าที่เป็นไปได้ทั้งหมด
        for (int i = 0; i <= MAX_VAL; i++) {
            if (count[i] == 0) continue;
            
            for (int j = i; j <= MAX_VAL; j++) {
                if (count[j] == 0) continue;
                
                int k = target - i - j;
                if (k < j || k > MAX_VAL) continue;
                if (count[k] == 0) continue;
                
                if (i == j && j == k) {
                    // กรณี i = j = k
                    long long n = count[i];
                    if (n >= 3) {
                        result += n * (n - 1) * (n - 2) / 6;
                    }
                } else if (i == j && j != k) {
                    // กรณี i = j ≠ k
                    long long n = count[i];
                    if (n >= 2) {
                        result += (n * (n - 1) / 2) * count[k];
                    }
                } else if (i != j && j == k) {
                    // กรณี i ≠ j = k
                    long long n = count[j];
                    if (n >= 2) {
                        result += count[i] * (n * (n - 1) / 2);
                    }
                } else {
                    // กรณี i < j < k
                    result += count[i] * count[j] * count[k];
                }
            }
        }
        
        return result % MOD;
    }
};