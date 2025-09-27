impl Solution {
    pub fn least_interval(tasks: Vec<char>, n: i32) -> i32 {
        if n == 0 {
            return tasks.len() as i32;
        }
        
        let mut count = vec![0; 26];
        
        // นับความถี่ของแต่ละ task
        for &task in &tasks {
            count[(task as u8 - b'A') as usize] += 1;
        }
        
        // เรียงลำดับความถี่จากมากไปน้อย
        count.sort_by(|a, b| b.cmp(a));
        
        // หาจำนวน task ที่มีความถี่สูงสุด
        let max_count = count[0];
        let mut num_max = 1;
        
        for i in 1..26 {
            if count[i] == max_count {
                num_max += 1;
            } else {
                break;
            }
        }
        
        // คำนวณเวลาขั้นต่ำ
        let min_time = (max_count - 1) * (n + 1) + num_max;
        
        min_time.max(tasks.len() as i32)
    }
}