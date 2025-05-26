impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        if (nums.len() < 3){
            return nums.len() as i32;
        }
        let mut i: usize = 2;
        while i < nums.len(){
            if (nums[i - 2] == nums[i - 1] && nums[i - 1] == nums[i]){
                nums.remove(i);
            }
            else{
                i+=1;
            }
        }
        return nums.len() as i32
    }
}