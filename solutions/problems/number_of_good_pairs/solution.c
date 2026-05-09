#define MAX_NUM 101

int numIdenticalPairs(int* nums, int numsSize) {
    int freq[MAX_NUM] = {0};  // frequency array
    int count = 0;
    
    for (int i = 0; i < numsSize; i++) {
        // จำนวนคู่ที่สามารถสร้างกับ nums[i] กับค่าที่เห็นมาก่อน
        count += freq[nums[i]];
        freq[nums[i]]++;
    }
    
    return count;
}