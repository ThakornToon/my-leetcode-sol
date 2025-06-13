impl Solution {
    fn maxSeq(nums: &Vec<i32>, n: usize) -> Vec<i32> {
        let mut result: Vec<i32> = Vec::new();
        let size = nums.len();
        let mut start = 0;
        
        for i in 0..n {
            let mut max_num = -1;
            let mut max_pos = 0;
            
            // หาตัวเลขที่มากที่สุดในส่วนที่เหลือ โดยให้เหลือตัวเลขพอสำหรับเลือกในขั้นตอนต่อไป
            for j in start..=(size - (n - i)) {
                if nums[j] > max_num {
                    max_num = nums[j];
                    max_pos = j;
                }
            }
            
            result.push(max_num);
            start = max_pos + 1;
        }
        
        return result;
    }

    fn isGreater(n1: &Vec<i32>, i: usize, n2: &Vec<i32>, j: usize) -> bool {
        let mut i = i;
        let mut j = j;
        while i < n1.len() && j < n2.len() {
            if n1[i] > n2[j] {
                return true;
            }
            else if n1[i] < n2[j] {
                return false;
            }
            i += 1;
            j += 1;
        }
        return (n1.len() - i) > (n2.len() - j);
    }

    fn merge(n1: &Vec<i32>, n2: &Vec<i32>) -> Vec<i32> {
        let mut merge: Vec<i32> = Vec::new();
        let mut i = 0;
        let mut j = 0;
        while i < n1.len() || j < n2.len() {
            if Self::isGreater(n1, i, n2, j) {
                merge.push(n1[i]);
                i += 1;
            } else {
                merge.push(n2[j]);
                j += 1;
            }
        }
        return merge;
    }

    pub fn max_number(nums1: Vec<i32>, nums2: Vec<i32>, k: i32) -> Vec<i32> {
        let k = k as usize;
        let mut ans: Vec<i32> = vec![-1; k];
        for i in 0..=k {
            if i > nums1.len() || k - i > nums2.len() {
                continue;
            }
            // sub-sequence from n1=i, from n2=k-i
            let s1: Vec<i32> = Self::maxSeq(&nums1, i);
            let s2: Vec<i32> = Self::maxSeq(&nums2, k - i);

            let temp = Self::merge(&s1, &s2);
            
            if Self::isGreater(&temp, 0, &ans, 0){
                ans = temp;
            }
        }
        return ans;
    }
}