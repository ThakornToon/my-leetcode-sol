class Solution {
public:
    int bestRotation(vector<int>& nums) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            if (nums[i] <= i) {
                // กรณี 1: nums[i] <= i
                // ได้คะแนนเมื่อ k ∈ [0, i - nums[i]] ∪ [i + 1, n - 1]
                
                diff[0]++;  // k=0 ได้คะแนน
                if (i - nums[i] + 1 < n) {
                    diff[i - nums[i] + 1]--;  // หมดช่วงแรก
                }
                
                if (i + 1 < n) {
                    diff[i + 1]++;  // เริ่มช่วงสอง
                }
                // ช่วงสองไปจนถึง k = n-1 ไม่ต้องลบ
            } else {
                // กรณี 2: nums[i] > i
                // ได้คะแนนเมื่อ k ∈ [i + 1, n - (nums[i] - i)]
                
                int start = i + 1;
                int end = n - (nums[i] - i);
                
                if (start < n) {
                    diff[start]++;  // เริ่มช่วงได้คะแนน
                }
                if (end + 1 < n) {
                    diff[end + 1]--;  // หมดช่วงได้คะแนน
                }
            }
        }
        
        // คำนวณคะแนนและหาค่า k ที่ดีที่สุด
        int maxScore = 0;
        int bestK = 0;
        int currentScore = 0;
        
        for (int k = 0; k < n; k++) {
            currentScore += diff[k];
            if (currentScore > maxScore) {
                maxScore = currentScore;
                bestK = k;
            }
        }
        
        return bestK;
    }
};