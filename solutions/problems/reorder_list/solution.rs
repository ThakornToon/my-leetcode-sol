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

use std::collections::VecDeque;

impl Solution {
    pub fn reorder_list(head: &mut Option<Box<ListNode>>) {
        // Step 1: เก็บ nodes ทั้งหมดใน VecDeque
        let mut deque = VecDeque::new();
        let mut current = head.take();
        
        while let Some(mut node) = current {
            let next = node.next.take();
            deque.push_back(node);
            current = next;
        }
        
        // Step 2: สร้าง dummy head
        let mut dummy = Box::new(ListNode::new(0));
        let mut tail = &mut dummy;
        
        // Step 3: สลับกันดึงจากหน้าและหลัง
        while !deque.is_empty() {
            // ดึงจากหน้า
            let front = deque.pop_front().unwrap();
            tail.next = Some(front);
            tail = tail.next.as_mut().unwrap();
            
            // ดึงจากหลัง (ถ้ามี)
            if !deque.is_empty() {
                let back = deque.pop_back().unwrap();
                tail.next = Some(back);
                tail = tail.next.as_mut().unwrap();
            }
        }
        
        // คืน ownership กลับไปที่ head
        *head = dummy.next.take();
    }
}