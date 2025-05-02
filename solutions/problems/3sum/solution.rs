impl Solution {
    pub fn three_sum(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut vv = Vec::new();
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
                if sum>0{
                    r-=1;
                }
                else if sum<0{
                    l+=1;
                }
                else{
                    vv.push(vec![nums[i], nums[l], nums[r]]);
                    l+=1;
                    while nums[l] == nums[l-1] && l<r{
                        l+=1;
                    }
                }
            }
        }
        return vv;
    }
}