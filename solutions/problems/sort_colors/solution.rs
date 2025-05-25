impl Solution {
    pub fn sort_colors(nums: &mut Vec<i32>) {
        let mut stop = false;
        let mut len = nums.len()-1;
        while !stop {
            stop = true;
            let mut i = 0;
            while i < len {
                if nums[i] > nums[i + 1] {
                    let temp = nums[i];
                    nums[i] = nums[i + 1];
                    nums[i + 1] = temp;
                    stop = false;
                }
                i+=1;
            }
            len-=1;
            if stop {
                break;
            }
        }
    }
}