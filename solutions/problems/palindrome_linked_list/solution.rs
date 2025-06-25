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
    fn reverse_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut prev = None;
        let mut curr = head;
        while let Some(mut node) = curr {
            let next = node.next.take();
            node.next = prev;
            prev = Some(node);
            curr = next;
        }
        prev
    }
    pub fn is_palindrome(head: Option<Box<ListNode>>) -> bool {
        let mut head = head;
        // List len
        let mut len = 0;
        let mut curr: &Option<Box<ListNode>> = &head;
        while let Some(node) = curr {
            len += 1;
            curr = &node.next;
        }
        
        // Split into two halves
        let mut curr: &mut Option<Box<ListNode>> = &mut head;
        for _ in 1..(len / 2) {
            curr = &mut curr.as_mut().unwrap().next;
        }
        
        let second_half = curr.as_mut().unwrap().next.take();
        let mut first_half = head;
        let mut second_half = Self::reverse_list(second_half);
        
        // Compare halves
        let mut result = true;
        let mut first = &first_half;
        let mut second = &second_half;
        for _ in 0..(len / 2) {
            if first.as_ref().unwrap().val != second.as_ref().unwrap().val {
                result = false;
                break;
            }
            first = &first.as_ref().unwrap().next;
            second = &second.as_ref().unwrap().next;
        }

        result
    }
}