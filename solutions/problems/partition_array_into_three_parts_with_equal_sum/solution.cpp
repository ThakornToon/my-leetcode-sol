class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int total = accumulate(arr.begin(), arr.end(), 0);
        
        // ถ้าผลรวมหารด้วย 3 ไม่ลงตัว
        if (total % 3 != 0) {
            return false;
        }
        
        int target = total / 3;
        int currentSum = 0;
        int count = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            currentSum += arr[i];
            
            if (currentSum == target) {
                count++;
                currentSum = 0;
                
                // ถ้าเจอ 2 ส่วนแล้ว และยังมีตัวเลขเหลือ
                if (count == 2 && i < arr.size() - 1) {
                    // ส่วนที่เหลือต้องรวมกันได้ target
                    int remainingSum = 0;
                    for (int j = i + 1; j < arr.size(); j++) {
                        remainingSum += arr[j];
                    }
                    return remainingSum == target;
                }
            }
        }
        
        return false;
    }
};