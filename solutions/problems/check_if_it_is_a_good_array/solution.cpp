class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        // gcd(a, b, c) = gcd(gcd(a, b), c) = gcd(a, gcd(b, c))
        int currentGcd = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            // ใช้ Euclidean algorithm
            currentGcd = gcd(currentGcd, nums[i]);
            
            // Optimization: ถ้า gcd เป็น 1 แล้ว ให้หยุดเลย
            if (currentGcd == 1) {
                return true;
            }
        }
        
        return currentGcd == 1;
    }
};