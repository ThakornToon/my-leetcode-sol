class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int totalSum = 0;
        
        for (int num : nums) {
            // ตรวจสอบว่ามีตัวหาร 4 ตัวหรือไม่
            int divisorCount = 0;
            int divisorSum = 0;
            
            // หาตัวหารจนถึง sqrt(num)
            for (int i = 1; i <= num / i; i++) {
                if (num % i == 0) {
                    if (i * i == num) {
                        // กรณี i เป็น sqrt(num) นับเป็นตัวเดียว
                        divisorCount += 1;
                        divisorSum += i;
                    } else {
                        // นับตัวหารคู่
                        divisorCount += 2;
                        divisorSum += i + (num / i);
                    }
                    
                    // ถ้ามีตัวหารเกิน 4 ตัวแล้ว ไปตัวต่อไปได้เลย
                    if (divisorCount > 4) {
                        break;
                    }
                }
            }
            
            if (divisorCount == 4) {
                totalSum += divisorSum;
            }
        }
        
        return totalSum;
    }
};