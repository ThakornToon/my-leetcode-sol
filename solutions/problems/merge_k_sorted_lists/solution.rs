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
    // ฟังก์ชัน merge สองลิสต์ที่เรียงแล้ว
    fn merge_two_lists(
        l1: Option<Box<ListNode>>, 
        l2: Option<Box<ListNode>>
    ) -> Option<Box<ListNode>> {
        match (l1, l2) {
            (None, None) => None,
            (Some(node), None) | (None, Some(node)) => Some(node),
            (Some(mut node1), Some(mut node2)) => {
                if node1.val < node2.val {
                    let next_node: Option<Box<ListNode>> = node1.next.take();
                    node1.next = Self::merge_two_lists(next_node, Some(node2));
                    Some(node1)
                } else {
                    let next_node: Option<Box<ListNode>> = node2.next.take();
                    node2.next = Self::merge_two_lists(Some(node1), next_node);
                    Some(node2)
                }
            }
        }
    }

    pub fn merge_k_lists(lists: Vec<Option<Box<ListNode>>>) -> Option<Box<ListNode>> {
        if lists.is_empty() {
            return None;
        }
        
        let mut result: Option<Box<ListNode>> = lists[0].clone();
        
        for i in 1..lists.len() {
            result = Self::merge_two_lists(result, lists[i].clone());
        }
        
        result
    }
}