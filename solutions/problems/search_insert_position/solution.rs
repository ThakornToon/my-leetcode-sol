impl Solution {
    pub fn search_insert(nums: Vec<i32>, target: i32) -> i32 {
        let mut c:i32 = 0;
        for i in nums{
            if i>=target{
                return c;
            }
            c+=1;
        }
        return c;
    }
}