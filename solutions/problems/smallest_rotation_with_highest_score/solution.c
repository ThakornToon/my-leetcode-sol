int bestRotation(int* nums, int numsSize) {
    int* diff = (int*)calloc(numsSize + 1, sizeof(int));
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] <= i) {
            // กรณี 1: nums[i] <= i
            // ได้คะแนนเมื่อ k ∈ [0, i - nums[i]] ∪ [i + 1, numsSize - 1]
            
            diff[0]++;  // k=0 ได้คะแนน
            if (i - nums[i] + 1 < numsSize) {
                diff[i - nums[i] + 1]--;  // หมดช่วงแรก
            }
            
            if (i + 1 < numsSize) {
                diff[i + 1]++;  // เริ่มช่วงสอง
            }
            // ช่วงสองไปจนถึง k = numsSize-1 ไม่ต้องลบ
        } else {
            // กรณี 2: nums[i] > i
            // ได้คะแนนเมื่อ k ∈ [i + 1, numsSize - (nums[i] - i)]
            
            int start = i + 1;
            int end = numsSize - (nums[i] - i) + 1;
            
            if (start < numsSize) {
                diff[start]++;  // เริ่มช่วงได้คะแนน
            }
            if (end < numsSize) {
                diff[end]--;    // หมดช่วงได้คะแนน
            }
        }
    }
    
    // คำนวณ prefix sum
    int maxScore = 0;
    int bestK = 0;
    int currentScore = 0;
    
    for (int k = 0; k < numsSize; k++) {
        currentScore += diff[k];
        if (currentScore > maxScore) {
            maxScore = currentScore;
            bestK = k;
        }
    }
    
    free(diff);
    return bestK;
}