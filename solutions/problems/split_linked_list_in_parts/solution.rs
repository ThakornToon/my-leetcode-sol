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
    pub fn split_list_to_parts(head: Option<Box<ListNode>>, k: i32) -> Vec<Option<Box<ListNode>>> {
        let mut n = 0;
        let mut curr: &Option<Box<ListNode>> = &head;
        while let Some(node) = curr {
            n += 1;
            curr = &node.next;
        }
        
        let k = k as usize;
        let chunk_size = n / k;
        let extra = n % k;
        
        let mut res: Vec<Option<Box<ListNode>>> = Vec::with_capacity(k);
        let mut curr: Option<Box<ListNode>> = head;
        
        for i in 0..k {
            let current_part_size = chunk_size + if i < extra { 1 } else { 0 };
            if current_part_size == 0 {
                res.push(None);
                continue;
            }
            
            let mut p: &mut Option<Box<ListNode>> = &mut curr;
            for _ in 0..current_part_size - 1 {
                if let Some(node) = p {
                    p = &mut node.next;
                }
            }
            
            let next_part: Option<Box<ListNode>> = if let Some(node) = p {
                node.next.take() // ตัดส่วนที่เหลือออก
            } else {
                None
            };
            
            res.push(curr);
            curr = next_part;
        }
        res
    }
}