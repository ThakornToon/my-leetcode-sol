int findDuplicate(int* nums, int numsSize) {
    // Phase 1: หาจุดพบกันในวงจร
    int tortoise = nums[0];
    int hare = nums[0];
    
    do {
        tortoise = nums[tortoise];        // ขยับ 1 ขั้น
        hare = nums[nums[hare]];          // ขยับ 2 ขั้น
    } while (tortoise != hare);
    
    // Phase 2: หาจุดเริ่มต้นวงจร (ตัวซ้ำ)
    int pointer1 = nums[0];
    int pointer2 = tortoise;
    
    while (pointer1 != pointer2) {
        pointer1 = nums[pointer1];
        pointer2 = nums[pointer2];
    }
    
    return pointer1;
}