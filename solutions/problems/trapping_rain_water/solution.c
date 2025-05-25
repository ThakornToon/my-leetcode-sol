int trap(int* height, int heightSize) {
    int left = 0; 
    int right = heightSize - 1;
    int leftMax = height[left];
    int rightMax = height[right];
    int water = 0;

    while (left < right) { //ไม่คิดปริมาตรของตำแหน่งแรกกับตำแหน่งสุดท้าย
        if (leftMax < rightMax) {
            left++;
            if (leftMax < height[left]) {
                leftMax = height[left];
            }
            water += leftMax - height[left];
        } 
        else {
            right--;
            if (rightMax < height[right]) {
                rightMax = height[right];
            }
            water += rightMax - height[right];
        }
    }
    return water;    
}