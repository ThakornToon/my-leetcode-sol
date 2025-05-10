impl Solution {
    pub fn next_permutation(nums: &mut Vec<i32>) {
        let mut i: usize = 1;
        let mut j: usize = 0;
        let mut max: i32 = 0;
        let l: usize = nums.len();
        while j < i && i<=l{
            if max <= nums[l-1-j]{
                if j+1 == i{
                    i+=1;
                }
                max = nums[l-1-j];
                //println!("{}", j);
            }
            else{
                let mut less_than_max = i32::MAX;
                let mut index = 0;
                for k in 0..j{
                    if nums[l-1-j] < nums[l-1-k]{
                        if nums[l-1-k]<=less_than_max{
                            less_than_max = nums[l-1-k];
                            index = l-1-k;
                        }
                    }
                }
                nums.swap(index, l-1-j);
                nums[l-j..l].sort();
                return;
            }
            j+=1;
        }

        if i > l{
            nums.sort();
        }
    }
}