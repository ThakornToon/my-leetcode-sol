use std::collections::HashMap;
impl Solution {
    pub fn next_greater_element(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        let mut stack = Vec::new();
        let mut mapping = HashMap::new();
        
        for num in nums2 {
            while let Some(&top) = stack.last() {
                if num > top {
                    mapping.insert(stack.pop().unwrap(), num);
                } else {
                    break;
                }
            }
            stack.push(num);
        }
        
        // สำหรับตัวที่เหลือใน stack ไม่มี next greater element
        for num in stack {
            mapping.insert(num, -1);
        }
        
        nums1.iter().map(|num| *mapping.get(num).unwrap()).collect()
    }
}