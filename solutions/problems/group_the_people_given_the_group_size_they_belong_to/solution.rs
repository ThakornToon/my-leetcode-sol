use std::collections::HashMap;

impl Solution {
    pub fn group_the_people(group_sizes: Vec<i32>) -> Vec<Vec<i32>> {
        let mut result: Vec<Vec<i32>> = Vec::new();
        let mut groups: HashMap<i32, Vec<i32>> = HashMap::new();
        
        for (i, &size) in group_sizes.iter().enumerate() {
            let i = i as i32;
            
            // เพิ่มคนเข้า groups ตามขนาด
            groups.entry(size).or_insert(Vec::new()).push(i);
            
            // ถ้ามีคนครบตามขนาดกลุ่มแล้ว
            if groups[&size].len() == size as usize {
                // นำกลุ่มนั้นออกจาก HashMap และเพิ่มใน result
                if let Some(group) = groups.remove(&size) {
                    result.push(group);
                }
            }
        }
        
        result
    }
}