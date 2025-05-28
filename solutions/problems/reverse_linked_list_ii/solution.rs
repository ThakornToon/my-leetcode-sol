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
    pub fn reverse_between(head: Option<Box<ListNode>>, left: i32, right: i32) -> Option<Box<ListNode>> {
        if left == right {
            return head;
        }
        let mut head = head;
        let mut current: &mut Option<Box<ListNode>> = &mut head;
        for _ in 1..left { 
            if let Some(node) = current {
                current = &mut node.next;
            }
        }
        let mut it: &mut Option<Box<ListNode>> = &mut current;
        let mut store_val: Vec<i32> = Vec::new();
        for _ in left..=right {
            if let Some(node) = it{
                store_val.push(node.val);
                it = &mut node.next;
            }
        }

        for _ in left..=right {
            if let Some(node) = current{
                node.val = store_val.pop().unwrap();
                current = &mut node.next;
            }
        }
        return head;
    }
}