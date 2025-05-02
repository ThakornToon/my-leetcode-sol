impl Solution {
    
    pub fn four_sum(nums: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        let mut vv = Vec::new();
        let mut nums = nums;
        nums.sort();
        if nums.len()<4{
            return vv;
        }
        
        for i in 0..(nums.len()-3){
            if i>0 && nums[i]==nums[i-1]{
                continue;
            }
            if target / 4 < nums[i] {
                break;
            }
            for j in (i+1)..(nums.len()-2){
                if j>i+1 && nums[j]==nums[j-1]{
                    continue;
                }
                let mut l = j+1;
                let mut r = nums.len()-1;
                while l<r{
                    let sum = nums[i] as i64 + nums[j] as i64 + nums[l] as i64 + nums[r] as i64;
                    if sum>i32::MAX as i64{
                        r-=1;
                    }
                    else if sum<i32::MIN as i64{
                        l+=1;
                    }
                    else{
                        let sum = sum as i32;
                        if sum<target{
                            l+=1;
                        }
                        else if sum>target{
                            r-=1;
                        }
                        else{
                            vv.push(vec![nums[i], nums[j], nums[l], nums[r]]);
                            l+=1;
                            while nums[l]==nums[l-1] && l<r{
                                l+=1;
                            }
                        }
                    }
                }
            }
            
        }
        return vv;
    }
}