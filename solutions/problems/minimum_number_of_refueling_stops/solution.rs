use std::collections::BinaryHeap;
impl Solution {
    pub fn min_refuel_stops(target: i32, start_fuel: i32, stations: Vec<Vec<i32>>) -> i32 {
        let mut heap = BinaryHeap::new();
        let mut stops = 0;
        let mut i = 0;
        let mut current_fuel = start_fuel;
        
        while current_fuel < target {
            // เก็บสถานีทั้งหมดที่สามารถไปถึงได้
            while i < stations.len() && stations[i][0] <= current_fuel {
                heap.push(stations[i][1]);  // BinaryHeap เป็น max-heap โดย default
                i += 1;
            }
            
            // ถ้าไม่มีสถานีให้เติมแล้ว
            if heap.is_empty() {
                return -1;
            }
            
            // เติมน้ำมันจากสถานีที่มีน้ำมันมากสุด
            current_fuel += heap.pop().unwrap();
            stops += 1;
        }
        
        stops
    }
}