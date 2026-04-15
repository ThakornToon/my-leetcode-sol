class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        // เรียง digits จากมากไปน้อย
        sort(digits.begin(), digits.end(), greater<int>());
        
        int sum = accumulate(digits.begin(), digits.end(), 0);
        vector<int> count(10, 0);
        
        for (int d : digits) {
            count[d]++;
        }
        
        int remainder = sum % 3;
        
        if (remainder != 0) {
            bool removed = false;
            
            // ลบ digit ที่มี remainder เท่ากับ remainder (ตัวเล็กสุด)
            for (int i = remainder; i <= 9; i += 3) {
                if (count[i] > 0) {
                    count[i]--;
                    removed = true;
                    break;
                }
            }
            
            // ถ้ายังไม่ถูกลบ ให้ลบ remainder 3-remainder สองตัว
            if (!removed) {
                int target = 3 - remainder;
                int removedCount = 0;
                for (int i = target; i <= 9; i += 3) {
                    while (count[i] > 0 && removedCount < 2) {
                        count[i]--;
                        removedCount++;
                    }
                    if (removedCount == 2) break;
                }
            }
        }
        
        // สร้างผลลัพธ์
        string result;
        for (int i = 9; i >= 0; i--) {
            result.append(count[i], '0' + i);
        }
        
        // กรณีไม่มีตัวเลข หรือมีแต่ 0
        if (result.empty() || result[0] == '0') {
            return result.empty() ? "" : "0";
        }
        
        return result;
    }
};