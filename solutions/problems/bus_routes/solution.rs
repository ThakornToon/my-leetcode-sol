use std::collections::{HashMap, VecDeque, HashSet};


impl Solution {
    pub fn num_buses_to_destination(routes: Vec<Vec<i32>>, source: i32, target: i32) -> i32 {
        if source == target {
            return 0;
        }
        
        // map ว่าแต่ละป้ายมีคะนไหนผ่านบ้าง
        let mut stop_to_routes: HashMap<i32, Vec<usize>> = HashMap::new();
        for (route_idx, route) in routes.iter().enumerate() {
            for &stop in route {
                stop_to_routes.entry(stop).or_insert(Vec::new()).push(route_idx);
            }
        }
        
        // BFS
        let mut queue = VecDeque::new();
        let mut visited_route = vec![false; routes.len()];
        
        // เริ่มจากทุกสายที่ผ่าน source
        if let Some(routes_with_source) = stop_to_routes.get(&source) {
            for &route in routes_with_source {
                queue.push_back(route);
                visited_route[route] = true; // บันทึกว่าเคยขึ้นคันไหนไปบ้าง
            }
        }
        
        let mut buses = 1; // นับว่าขึ้นไปกี่คัน
        
        while !queue.is_empty() {
            let size = queue.len();
            // หาไปทีละ level
            for _ in 0..size {
                let curr_route = queue.pop_front().unwrap(); // คันปัจจุบัน
                
                // ตรวจสอบทุกป้ายในสายนี้
                for &stop in &routes[curr_route] {
                    if stop == target {
                        return buses;
                    }
                    
                    // ดูสายอื่นๆ ที่ผ่านป้ายนี้
                    if let Some(next_routes) = stop_to_routes.get(&stop) {
                        for &next_route in next_routes {
                            if !visited_route[next_route] { // เคยขึ้นรึยัง
                                visited_route[next_route] = true; // บันทึกว่าเคยขึ้นคันไหนไปบ้าง
                                queue.push_back(next_route); // ลองลงแล้วไปขึ้นคันใหม่
                            }
                        }
                    }
                }
            }
            buses += 1;
        }
        
        -1
    }
}