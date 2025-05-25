impl Solution {
    pub fn trap(height: Vec<i32>) -> i32 {
        let mut left = 0; 
        let mut right = height.len() - 1;
        let mut leftMax = height[left];
        let mut rightMax = height[right];
        let mut water = 0;

        while (left < right) { //ไม่คิดปริมาตรของตำแหน่งแรกกับตำแหน่งสุดท้าย
            if (leftMax < rightMax) {
                left+=1;
                leftMax = leftMax.max(height[left]);
                water += leftMax - height[left];
            } 
            else {
                right-=1;
                rightMax = rightMax.max(height[right]);
                water += rightMax - height[right];
            }
        }

        return water;
    }
}