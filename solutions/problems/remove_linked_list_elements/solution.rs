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
    pub fn remove_elements(head: Option<Box<ListNode>>, val: i32) -> Option<Box<ListNode>> {
        let mut head = head;
        let mut current: &mut Option<Box<ListNode>> = &mut head;
        
        while let Some(node) = current {
            if node.val == val {
                *current = node.next.take();
            } else {
                current = &mut current.as_mut().unwrap().next;
            }
        }
        head
    }
}