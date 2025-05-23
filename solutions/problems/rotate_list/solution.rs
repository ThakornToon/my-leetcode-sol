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
    pub fn rotate_right(head: Option<Box<ListNode>>, k: i32) -> Option<Box<ListNode>> {
        let mut v: Vec<i32> = Vec::new();
        let mut node = &head;
        while let Some(n) = node {
            v.push(n.val);
            node = &n.next;
        }
        let mut answer = None;
        for i in (0..v.len()).rev() {
            let j = k as usize % v.len(); //กันกรณี 0%0
            answer = Some(Box::new(ListNode { //ทำจากหลังมาหน้า
                val: v[(v.len() + i - j) % v.len()],
                next: answer
            }))
        }
        answer
    }
}