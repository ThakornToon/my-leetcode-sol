class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_set<int> seen;
        unordered_set<int> used;
        int count = 0;
        
        for (int num : nums) {
            // ดูว่าเคยเห็นค่าที่ต้องการก่อนหน้ารึยัง และ ค่านั้นถูกใช้ไปรึยัง 5 - 3 = 2 เจอ 5 จะหา 3 ถ้าเคยเลือก 3 แปลว่าเคยเจอ 5 แล้ว
            if (k == 0) {
                if (seen.count(num) && !used.count(num)) {
                    count++;
                    used.insert(num);
                }
            } else {
                if (seen.count(num - k) && !used.count(num - k)) {
                    count++;
                    used.insert(num - k);
                }
                if (seen.count(num + k) && !used.count(num)) {
                    count++;
                    used.insert(num);
                }
            }

            seen.insert(num);
        }
        
        return count;
    }
};