impl Solution {
    pub fn total_fruit(fruits: Vec<i32>) -> i32 {
        use std::collections::HashMap;
        
        let mut count = HashMap::new();
        let mut left = 0;
        let mut max_len = 0;
        
        for (right, &fruit) in fruits.iter().enumerate() {
            *count.entry(fruit).or_insert(0) += 1;
            
            // ถ้ามีมากกว่า 2 ประเภท
            while count.len() > 2 {
                let left_fruit = fruits[left];
                if let Some(cnt) = count.get_mut(&left_fruit) {
                    *cnt -= 1;
                    if *cnt == 0 {
                        count.remove(&left_fruit);
                    }
                }
                left += 1;
            }
            
            max_len = max_len.max((right - left + 1) as i32);
        }
        
        max_len
    }
}