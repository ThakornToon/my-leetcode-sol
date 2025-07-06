int minMoves(int* nums, int numsSize) {
    // หาค่าต่ำสุดในอาร์เรย์
    int min_num = INT_MAX;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < min_num) {
            min_num = nums[i];
        }
    }
    
    // คำนวณจำนวนการเคลื่อนไหวรวม
    int moves = 0;
    for (int i = 0; i < numsSize; i++) {
        moves += nums[i] - min_num;
    }
    
    return moves;
}