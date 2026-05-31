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
    pub fn swap_pairs(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        // สร้าง dummy node
        let mut dummy: Box<ListNode> = Box::new(ListNode {
            val: 0,
            next: head,
        });
        
        let mut prev = &mut dummy;
        
        // วนลูปตราบใดที่ยังมีอย่างน้อย 2 โหนด
        while let Some(mut first) = prev.next.take() {
            if let Some(mut second) = first.next.take() {
                // สลับตำแหน่ง: first กับ second
                first.next = second.next.take();
                second.next = Some(first);
                prev.next = Some(second);
                
                // เลื่อน prev ไปที่ second (ข้ามคู่ที่สลับแล้ว)
                prev = prev.next.as_mut().unwrap().next.as_mut().unwrap();
            } else {
                // ถ้ามีแค่โหนดเดียว ให้คืนค่ากลับ
                prev.next = Some(first);
                break;
            }
        }
        
        dummy.next
    }
}