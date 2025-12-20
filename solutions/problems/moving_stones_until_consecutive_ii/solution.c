/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int* numMovesStonesII(int* stones, int stonesSize, int* returnSize) {
    qsort(stones, stonesSize, sizeof(int), cmp);
    
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    
    int n = stonesSize;
    
    // Maximum moves 
    // Total empty positions = (stones[n-1] - stones[0] + 1) - n
    // Maximum moves = total_empty - min(left_gap, right_gap)
    // ครั้งแรกเลือกไปวางให้ติดกันจากนั้นขยับไปเรื่อยๆที่ละช่องว่าง
    int total_empty = (stones[n-1] - stones[0] + 1) - n;
    int left_gap = stones[1] - stones[0] - 1;
    int right_gap = stones[n-1] - stones[n-2] - 1;
    int max_moves = total_empty - (left_gap < right_gap ? left_gap : right_gap);
    result[1] = max_moves;
    
    // Minimum moves
    int min_moves = n - 1;
    int j = 0;
    
    // Sliding window ความยาว n ที่มีหินมากสุด
    for (int i = 0; i < n; i++) { // ตำแน่งเริ่ม window(ตำแหน่งหินก้อนแรก)
        // ใช้ j เลื่อนทางขวาขณะที่นับจำนวนหิน stones[j] - stones[i] + 1 <= n
        while (j + 1 < n && stones[j + 1] - stones[i] + 1 <= n) {
            j++;
        } 
        
        int stones_in_window = j - i + 1;
        
        // Special case: มีหินติดกัน n-1 ในความยาว n ต้อง move แบบพิเศษ
        if (stones_in_window == n - 1 && stones[j] - stones[i] + 1 == n - 1) {
            min_moves = 2 < min_moves ? 2 : min_moves;
        } else { // move ก้อนที่เหลือมาให้สั้นที่สุด
            int moves_needed = n - stones_in_window;
            min_moves = moves_needed < min_moves ? moves_needed : min_moves;
        }
    }
    
    result[0] = min_moves;
    return result;
}