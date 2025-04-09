impl Solution {
    pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
        let mut i:usize = 0;
        let mut c = 0;
        let mut j = nums.len();
        while i<j{
            if(nums[i]==val){
                nums.remove(i);
                i-=1;
                j-=1;
            }
            else{
                c+=1;
            }
            i+=1;
        }
        return c;
    }
}