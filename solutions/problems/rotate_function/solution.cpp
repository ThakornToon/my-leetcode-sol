// F(k) = F(k-1) + sum - n * nums[n-k]
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int sum = 0;
        int f = 0;
        
        // คำนวณ sum และ F(0)
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            f += i * nums[i];
        }
        
        int max_f = f;
        
        // คำนวณ F(k) สำหรับ k = 1 ถึง n-1
        for (int k = 1; k < n; k++) {
            f = f + sum - n * nums[n - k];
            max_f = max(max_f, f);
        }
        
        return max_f;
    }
};