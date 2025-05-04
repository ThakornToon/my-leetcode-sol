impl Solution {
    pub fn can_jump(nums: Vec<i32>) -> bool {
        let mut furthest_reachable = 0;

        for i in 0..nums.len()-1 {
            furthest_reachable = furthest_reachable.max(i + nums[i] as usize);
            if furthest_reachable == i {
                return false;
            }
        }
        return true
    }
}