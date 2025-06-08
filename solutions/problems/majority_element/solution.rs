impl Solution {
    pub fn majority_element(nums: Vec<i32>) -> i32 {
        let mut count = 1;
        let mut candi = nums[0];
        for i in 1..nums.len() {
            if count == 0 {
                candi = nums[i];
            }

            if candi == nums[i] {
                count+=1;
            }
            else {
                count-=1;
            }
        }
        return candi;
    }
}