impl Solution {
    pub fn find132pattern(nums: Vec<i32>) -> bool {
        let mut stack: Vec<i32> = Vec::new();
        let mut s3 = i32::MIN;  

        for &num in nums.iter().rev() {
            if num < s3 {
                return true;
            }
            
            while let Some(&top) = stack.last() {
                if top < num {
                    s3 = stack.pop().unwrap();
                } else {
                    break;
                }
            }
            
            stack.push(num);
        }
        
        false
    }
}