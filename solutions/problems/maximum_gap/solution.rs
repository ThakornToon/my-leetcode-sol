impl Solution {
    pub fn maximum_gap(nums: Vec<i32>) -> i32 {
        let size = nums.len();
        let mut min_val = i32::MAX;
        let mut max_val = i32::MIN;
        for i in 0..size {
            if max_val < nums[i] {
                max_val = nums[i];
            }
            if min_val > nums[i] {
                min_val = nums[i];
            }
        }
        if min_val == max_val {
            return 0;
        }
        let bucket_size = 1.max((max_val - min_val) as usize / (size - 1)); //เมื่อเรียงลำดับตัวเลข n ตัวจะมีช่องว่างระหว่างตัวเลขที่อยู่ติดกันทั้งหมด n-1 ช่อง (average gap)
        let bucket_num = (max_val - min_val) as usize / bucket_size + 1;
        let mut bucket_largest = vec![i32::MIN; bucket_num];
        let mut bucket_smallest = vec![i32::MAX; bucket_num];
        for i in 0..size {
            let index = (nums[i] - min_val) as usize / bucket_size;
            bucket_largest[index] = bucket_largest[index].max(nums[i]);
            bucket_smallest[index] = bucket_smallest[index].min(nums[i]);
        }

        let mut max_gap = 0;
        let mut i = 0;
        let mut j = 1;
        while j < bucket_num {
            if bucket_largest[j] == i32::MIN {
                j+=1;
            }
            else if bucket_largest[i] == i32::MIN {
                i+=1;
            }
            else{
                max_gap = max_gap.max(bucket_smallest[j] - bucket_largest[i]);
                i+=1;
                j+=1;
            }
        }
        return max_gap;
    }
}