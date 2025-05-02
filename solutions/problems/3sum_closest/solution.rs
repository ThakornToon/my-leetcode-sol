impl Solution {
    pub fn three_sum_closest(nums: Vec<i32>, target: i32) -> i32 {
        let mut c = i32::MAX;
        let mut m = target;
        let mut nums = nums;
        nums.sort();
        for i in 0..(nums.len()-2){
            if i>0 && nums[i]==nums[i-1]{
                continue;
            }
            let mut l = i+1;
            let mut r = nums.len()-1;
            while l<r{
                let sum = nums[i] + nums[l] + nums[r];
                if sum>target{
                    if c>sum-target{
                        c=sum-target;
                        m=sum;
                    }
                    r-=1;
                }
                else if sum<=target{
                    if c>target-sum{
                        c=target-sum;
                        m=sum;
                    }
                    l+=1;
                }
            }
        }
        return m;
    }
}