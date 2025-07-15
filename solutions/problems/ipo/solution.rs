use std::collections::BinaryHeap;

impl Solution {
    pub fn find_maximized_capital(k: i32, w: i32, profits: Vec<i32>, capital: Vec<i32>) -> i32 {
        let mut projects: Vec<(i32, i32)> = capital.into_iter().zip(profits.into_iter()).collect();
        
        // เรียงตามทุนที่ต้องการ (capital)
        projects.sort_unstable_by_key(|&(c, _)| c);
        
        let mut max_heap = BinaryHeap::new();
        let mut current = 0;
        let mut w = w;
        
        for _ in 0..k {
            // เพิ่มโครงการที่ทำได้ลงใน heap
            while current < projects.len() && projects[current].0 <= w {
                max_heap.push(projects[current].1);
                current += 1;
            }
            
            if max_heap.is_empty() {
                break;
            }
            
            // เลือกโครงการที่ให้กำไรสูงสุด
            w += max_heap.pop().unwrap();
        }
        
        w
    }
}