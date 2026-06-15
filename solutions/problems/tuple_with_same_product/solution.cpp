class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> productCount;
        
        // นับความถี่ของผลคูณทุกคู่
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int product = nums[i] * nums[j];
                productCount[product]++;
            }
        }
        
        long long result = 0;
        
        // คำนวณจำนวน tuple
        for (auto& [product, count] : productCount) {
            if (count >= 2) {
                // C(count, 2) = count * (count-1) / 2
                // แต่ละคู่สามาถจัดเรียงได้ 8 แบบ
                result += (long long)count * (count - 1) / 2 * 8;
            }
        }
        
        return (int)result;
    }
};