impl Solution {
    pub fn jump(nums: Vec<i32>) -> i32 {
        let mut furthest_reachable:usize = 0;
        let mut step = 0;
        let mut end = 0;

        for i in 0..nums.len()-1 {
            furthest_reachable = furthest_reachable.max(i + nums[i] as usize);
            if i == end {
                end = furthest_reachable;
                step+=1;
            }
        }
        return step;
    }
}