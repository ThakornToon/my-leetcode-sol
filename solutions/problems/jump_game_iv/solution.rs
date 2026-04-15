use std::collections::{HashMap, VecDeque};

impl Solution {
    pub fn min_jumps(arr: Vec<i32>) -> i32 {
        let n = arr.len();
        if n == 1 {
            return 0;
        }
        
        // สร้าง map จัดกลุ่ม indices ตามค่า
        let mut groups: HashMap<i32, Vec<usize>> = HashMap::new();
        for (i, &val) in arr.iter().enumerate() {
            groups.entry(val).or_insert(Vec::new()).push(i);
        }
        
        let mut dist = vec![-1; n];
        let mut queue = VecDeque::new();
        
        queue.push_back(0);
        dist[0] = 0;
        
        while let Some(curr) = queue.pop_front() {
            if curr == n - 1 {
                return dist[curr];
            }
            
            // กระโดดไป curr+1
            if curr + 1 < n && dist[curr + 1] == -1 {
                dist[curr + 1] = dist[curr] + 1;
                queue.push_back(curr + 1);
            }
            
            // กระโดดไป curr-1
            if curr > 0 && dist[curr - 1] == -1 {
                dist[curr - 1] = dist[curr] + 1;
                queue.push_back(curr - 1);
            }
            
            // กระโดดไป indices ที่มีค่าเท่ากัน
            let val = arr[curr];
            if let Some(indices) = groups.remove(&val) {
                for &next in &indices {
                    if dist[next] == -1 {
                        dist[next] = dist[curr] + 1;
                        queue.push_back(next);
                    }
                }
            }
        }
        
        -1
    }
}