int totalHammingDistance(int* nums, int numsSize) {
    int total = 0;
    for (int i = 0; i < 32; i++) { // ดูทีละตำแหน่งบิต
        int count = 0;
        for (int j = 0; j < numsSize; j++) {
            count += (nums[j] >> i) & 1;
        }
        total += count * (numsSize - count); // นำจำนวนบิตที่เป็น 1 * จำนวนบิตที่เป็น 0 เพราะจับคู่ทุกความเป็นไปได้
    }
    return total;
}