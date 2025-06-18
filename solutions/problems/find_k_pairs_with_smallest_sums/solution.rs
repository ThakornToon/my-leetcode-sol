impl Solution {
    pub fn k_smallest_pairs(nums1: Vec<i32>, nums2: Vec<i32>, k: i32) -> Vec<Vec<i32>> {
        let mut res = Vec::new();
        let k = k as usize;
        let mut heap = std::collections::BinaryHeap::new();
        
        for &x in nums1.iter() {
            for &y in nums2.iter() {
                let sum = x + y;
                if heap.len() < k {
                    heap.push((sum, x, y));
                } else if sum < heap.peek().unwrap().0 {
                    heap.pop();
                    heap.push((sum, x, y));
                } else {
                    break;
                }
            }
        }
        
        while let Some((_, x, y)) = heap.pop() {
            res.push(vec![x, y]);
        }
        
        res
    }
}