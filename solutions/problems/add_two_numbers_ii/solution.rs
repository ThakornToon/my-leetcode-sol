// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn add_two_numbers(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut stack1 = Vec::new();
        let mut stack2 = Vec::new();
        
        // เติมค่าเข้า stack สำหรับ l1
        let mut current = l1.as_ref();
        while let Some(node) = current {
            stack1.push(node.val);
            current = node.next.as_ref();
        }
        
        // เติมค่าเข้า stack สำหรับ l2
        let mut current = l2.as_ref();
        while let Some(node) = current {
            stack2.push(node.val);
            current = node.next.as_ref();
        }
        
        let mut carry = 0;
        let mut result: Option<Box<ListNode>> = None;
        while !stack1.is_empty() || !stack2.is_empty() || carry != 0 {
            let mut sum = carry;
            
            if let Some(val) = stack1.pop() {
                sum += val;
            }
            
            if let Some(val) = stack2.pop() {
                sum += val;
            }
            
            carry = sum / 10;
            let digit = sum % 10;
            
            // สร้างโหนดใหม่และเชื่อมกับผลลัพธ์ที่สร้างไว้ก่อนหน้า
            let mut new_node = Box::new(ListNode::new(digit));
            new_node.next = result;
            result = Some(new_node);
        }
        
        result
    }
}