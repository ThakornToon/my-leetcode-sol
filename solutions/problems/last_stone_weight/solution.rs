use std::collections::BinaryHeap;

impl Solution {
    pub fn last_stone_weight(stones: Vec<i32>) -> i32 {
        // BinaryHeap in Rust is a max-heap by default
        let mut heap = BinaryHeap::new();
        
        // Push all stones into the heap
        for stone in stones {
            heap.push(stone);
        }
        
        // Process until one or zero stones remain
        while heap.len() > 1 {
            let y = heap.pop().unwrap();  // heaviest stone
            let x = heap.pop().unwrap();  // second heaviest
            
            if x != y {
                heap.push(y - x);
            }
            // If equal, both are destroyed
        }
        
        // Return the last stone weight or 0
        heap.pop().unwrap_or(0)
    }
}