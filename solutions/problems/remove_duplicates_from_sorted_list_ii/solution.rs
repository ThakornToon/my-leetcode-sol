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
    pub fn delete_duplicates(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        if head.is_none()  {
            return None;
        }
        let mut dummy: Box<ListNode> = Box::new(ListNode::new(0));
        dummy.next = head;
        let mut prev: &mut ListNode = dummy.as_mut();
        while let Some(mut current) = prev.next.take() { //current = next node of prev and change prev.next = None
            let mut del = false; 
            while let Some(next) = current.next.as_mut() {
                if current.val == next.val { //Check if we should delete or not
                    del = true;
                    current.next = next.next.take();  // Skip the next node that has the same value as current and point to the next.next node 
                }
                else {
                    break;
                }
                //Keep searching until you find a unique node
            }
            if del {
                prev.next = current.next; //Now we have a current node that we don't want, we will let prev point to the next node
            }
            else { //If there are no duplicate nodes, prev is moved forward.
                prev.next = Some(current); //Now prev.next points to None, so it points back to the current node
                prev = prev.next.as_mut().unwrap();
            }
        }
        return dummy.next;
    }
}