/*
1. ต้องจ่ายให้ทุกคนตาม อัตราส่วนเงินเดือนต่อประสิทธิภาพที่เท่ากัน = r = W / Q
2. แต่ละคนต้องได้อย่างน้อยเงินเดือนขั้นต่ำที่ตัวเองต้องการ

COST i = Qi * r

เรียงตาม r จากน้อยไปมาก
ใช้ max-heap หาคน k-1 คนก่อนหน้าที่มี quality น้อยที่สุด + ตัวคนที่กำหนด r อีก 1
ทุกครั้งที่มีคนใหม่ ลองให้เขาเป็นคนกำหนด r

ถ้าคนที่ r สูงอยู่ในทีม เราต้องใช้ r ของเขาเลยต้องให้คนที่ r สูงเป็นคนกำหนด(คนล่าสุดที่พิจารณา)
*/
use std::collections::BinaryHeap;

impl Solution {
    pub fn mincost_to_hire_workers(quality: Vec<i32>, wage: Vec<i32>, k: i32) -> f64 {
        let n = quality.len();
        let k = k as usize;
        
        // สร้าง vector ของ (ratio, quality)
        let mut workers: Vec<(f64, i32)> = Vec::with_capacity(n);
        for i in 0..n {
            let ratio = wage[i] as f64 / quality[i] as f64;
            workers.push((ratio, quality[i]));
        }
        
        // เรียงตาม ratio จากน้อยไปมาก
        workers.sort_by(|a, b| a.0.partial_cmp(&b.0).unwrap());
        
        // Max-heap สำหรับ quality มากไปน้อย
        let mut heap = BinaryHeap::new();
        let mut total_quality = 0;
        let mut min_cost = f64::MAX;
        
        for (ratio, q) in workers {
            total_quality += q;
            
            if heap.len() >= k {
                if let Some(max_q) = heap.pop() {
                    total_quality -= max_q;
                }
            }
            heap.push(q);  // BinaryHeap เป็น max-heap โดย default
            if heap.len() == k {
                let cost = ratio * total_quality as f64;
                if cost < min_cost {
                    min_cost = cost;
                }
            }
        }
        
        min_cost
    }
}