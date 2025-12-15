int maxWidthRamp(int* nums, int numsSize) {
    int* stack = (int*)malloc(numsSize * sizeof(int));
    int top = -1;
    
    // สร้าง stack ที่เก็บดัชนีของค่าที่ลดลง monotonic
    for (int i = 0; i < numsSize; i++) {
        if (top == -1 || nums[stack[top]] > nums[i]) {
            stack[++top] = i;
        }
    }
    
    int maxWidth = 0;
    // สแกนจากขวาไปซ้าย
    for (int j = numsSize - 1; j >= 0; j--) {
        while (top >= 0 && nums[stack[top]] <= nums[j]) {
            int i = stack[top--];
            if (j - i > maxWidth) {
                maxWidth = j - i;
            }
        }
    }
    
    free(stack);
    return maxWidth;

}