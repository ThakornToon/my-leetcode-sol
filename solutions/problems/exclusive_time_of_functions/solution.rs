impl Solution {
    pub fn exclusive_time(n: i32, logs: Vec<String>) -> Vec<i32> {
        let n = n as usize;
        let mut result = vec![0; n];
        let mut stack: Vec<usize> = Vec::new(); // เก็บ function_id
        let mut prev_time = 0;
        
        for log in logs {
            let parts: Vec<&str> = log.split(':').collect();
            let id: usize = parts[0].parse().unwrap();
            let event_type = parts[1];
            let timestamp: i32 = parts[2].parse().unwrap();
            
            match event_type {
                "start" => {
                    if let Some(&prev_id) = stack.last() {
                        result[prev_id] += timestamp - prev_time;
                    }
                    stack.push(id);
                    prev_time = timestamp;
                }
                "end" => {
                    if let Some(current_id) = stack.pop() {
                        result[current_id] += timestamp - prev_time + 1;
                    }
                    prev_time = timestamp + 1;
                }
                _ => {}
            }
        }
        
        result
    }
}