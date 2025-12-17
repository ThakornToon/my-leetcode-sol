class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> answer;
        int evenSum = 0;
        
        // คำนวณ sum เริ่มต้นของเลขคู่
        for (int num : nums) {
            if (num % 2 == 0) {
                evenSum += num;
            }
        }
        
        // ประมวลผลแต่ละ query
        for (auto& query : queries) {
            int val = query[0];
            int index = query[1];
            
            // ถ้าค่าเดิมเป็นเลขคู่
            if (nums[index] % 2 == 0) {
                evenSum -= nums[index];
            }
            
            // อัพเดตค่า
            nums[index] += val;
            
            // ถ้าค่าใหม่เป็นเลขคู่
            if (nums[index] % 2 == 0) {
                evenSum += nums[index];
            }
            
            answer.push_back(evenSum);
        }
        
        return answer;
    }
};