impl Solution {
    pub fn max_distance(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
        let mut max_dist = 0;
        let mut j = 0;
        
        for i in 0..nums1.len() {
            while j < nums2.len() && nums1[i] <= nums2[j] {
                j += 1;
            }
            if j > i {
                max_dist = max_dist.max(j - i - 1);
            }
        }
        
        max_dist as i32
    }
}