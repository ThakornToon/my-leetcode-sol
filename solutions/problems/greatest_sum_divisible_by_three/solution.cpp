class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        vector<int> remain1, remain2;
        
        // 1. คำนวณผลรวมและแยกตัวเลขตาม remainder
        for (int num : nums) {
            sum += num;
            if (num % 3 == 1) {
                remain1.push_back(num);
            } else if (num % 3 == 2) {
                remain2.push_back(num);
            }
        }
        
        // 2. เรียงลำดับเพื่อหาค่าน้อยที่สุด
        sort(remain1.begin(), remain1.end());
        sort(remain2.begin(), remain2.end());
        
        int remainder = sum % 3;
        
        // 3. ถ้าหารลงตัวแล้ว
        if (remainder == 0) {
            return sum;
        }
        
        int result = 0;
        
        // 4. กรณี remainder == 1
        if (remainder == 1) {
            // ทางเลือก 1: ลบ 1 ตัวจาก remain1
            if (remain1.size() >= 1) {
                result = max(result, sum - remain1[0]);
            }
            
            // ทางเลือก 2: ลบ 2 ตัวจาก remain2
            if (remain2.size() >= 2) {
                result = max(result, sum - remain2[0] - remain2[1]);
            }
        }
        // 5. กรณี remainder == 2
        else { // remainder == 2
            // ทางเลือก 1: ลบ 1 ตัวจาก remain2
            if (remain2.size() >= 1) {
                result = max(result, sum - remain2[0]);
            }
            
            // ทางเลือก 2: ลบ 2 ตัวจาก remain1
            if (remain1.size() >= 2) {
                result = max(result, sum - remain1[0] - remain1[1]);
            }
        }
        
        return result;
    }
};