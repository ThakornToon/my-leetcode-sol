impl Solution {
    pub fn find_duplicate(nums: Vec<i32>) -> i32 {
        let mut tortoise = nums[0];
        let mut hare = nums[0];
        
        // Phase 1: หาจุดพบกันในวงจร
        loop {
            tortoise = nums[tortoise as usize];
            hare = nums[nums[hare as usize] as usize];
            
            if tortoise == hare {
                break;
            }
        }
        
        // Phase 2: หาจุดเริ่มต้นวงจร
        let mut pointer1 = nums[0];
        let mut pointer2 = tortoise;
        
        while pointer1 != pointer2 {
            pointer1 = nums[pointer1 as usize];
            pointer2 = nums[pointer2 as usize];
        }
        
        pointer1
    }
}