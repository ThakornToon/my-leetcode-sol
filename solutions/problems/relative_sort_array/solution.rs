impl Solution {
    pub fn relative_sort_array(arr1: Vec<i32>, arr2: Vec<i32>) -> Vec<i32> {
        use std::collections::HashMap;
        
        let mut freq: HashMap<i32, i32> = HashMap::new();
        
        // นับความถี่
        for &num in &arr1 {
            *freq.entry(num).or_insert(0) += 1;
        }
        
        let mut result = Vec::new();
        
        // ใส่ตามลำดับใน arr2
        for &num in &arr2 {
            if let Some(&count) = freq.get(&num) {
                for _ in 0..count {
                    result.push(num);
                }
                freq.remove(&num);
            }
        }
        
        // เก็บตัวเลขที่เหลือและเรียงลำดับ
        let mut remaining: Vec<i32> = Vec::new();
        for (&num, &count) in &freq {
            for _ in 0..count {
                remaining.push(num);
            }
        }
        remaining.sort();
        
        // รวมผลลัพธ์
        result.extend(remaining);
        result
    }
}