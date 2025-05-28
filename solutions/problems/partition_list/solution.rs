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
    pub fn partition(mut head: Option<Box<ListNode>>, x: i32) -> Option<Box<ListNode>> {
        let mut before: ListNode = ListNode::new(0);
        let mut after: ListNode = ListNode::new(0);
        let mut before_tail: &mut ListNode = &mut before;
        let mut after_tail: &mut ListNode = &mut after;

        while let Some(mut node) = head { //head ย้ายเจ้าของ
            head = node.next.take(); //เอาโหนดที่เหลือกลับมา
            if node.val < x {
                before_tail.next = Some(node);
                before_tail = before_tail.next.as_mut().unwrap();
            } 
            else {
                after_tail.next = Some(node);
                after_tail = after_tail.next.as_mut().unwrap();
            }
        }

        before_tail.next = after.next.take();

        return before.next;
    }
}