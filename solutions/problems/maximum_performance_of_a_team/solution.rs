use std::collections::BinaryHeap;
use std::cmp::Reverse;

impl Solution {
    const MOD: i64 = 1_000_000_007;

    pub fn max_performance(n: i32, speed: Vec<i32>, efficiency: Vec<i32>, k: i32) -> i32 {
        let n = n as usize;
        let k = k as usize;
        
        let mut engineers: Vec<(i32, i32)> = (0..n)
            .map(|i| (efficiency[i], speed[i]))
            .collect();
        
        // เรียงตาม efficiency จากมากไปน้อย
        engineers.sort_by(|a, b| b.0.cmp(&a.0));
        
        let mut min_heap = BinaryHeap::new();  // ใช้ Reverse เพื่อให้เป็น min-heap
        let mut sum_speed: i64 = 0;
        let mut max_perf: i64 = 0;
        
        for &(eff, spd) in &engineers {
            // ถ้า heap เต็ม ให้เอาความเร็วน้อยที่สุดออก
            if min_heap.len() == k {
                if let Some(Reverse(smallest)) = min_heap.pop() {
                    sum_speed -= smallest as i64;
                }
            }
            
            // เพิ่มความเร็วปัจจุบัน
            min_heap.push(Reverse(spd));
            sum_speed += spd as i64;
            
            // คำนวณประสิทธิภาพ
            let perf = sum_speed * eff as i64;
            max_perf = max_perf.max(perf);
        }
        
        (max_perf % Self::MOD) as i32
    }
}