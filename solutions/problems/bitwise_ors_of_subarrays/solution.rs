/*
arr = [1, 2, 3, 4]

เราต้องการหา OR ของทุก subarray:
[1], [1,2], [1,2,3], [1,2,3,4]
[2], [2,3], [2,3,4]
[3], [3,4]
[4]
*/
impl Solution {
    pub fn subarray_bitwise_o_rs(arr: Vec<i32>) -> i32 {
        use std::collections::HashSet;
        
        let mut result = HashSet::new();
        let mut cur = HashSet::new();
        
        for &num in &arr {
            let mut next = HashSet::new();
            next.insert(num);
            
            for &val in &cur {
                next.insert(val | num);
            }
            
            // เพิ่มเข้า result
            for &val in &next {
                result.insert(val);
            }
            
            cur = next;
        }
        
        result.len() as i32
    }
}