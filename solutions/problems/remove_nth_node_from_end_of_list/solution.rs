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
    pub fn remove_nth_from_end(head: Option<Box<ListNode>>, n: i32) -> Option<Box<ListNode>> {
        // สร้าง dummy node เพื่อจัดการกรณีลบ head
        let mut dummy = Box::new(ListNode {
            val: 0,
            next: head,
        });
        
        // ใช้ two-pointer technique
        // ต้อง clone dummy เพื่อให้ได้ ownership สองอัน
        let mut first = dummy.clone();
        let mut second = &mut dummy;
        
        // ขยับ first ไปข้างหน้า n ครั้ง
        for _ in 0..n {
            if let Some(node) = first.next {
                first = node;
            }
        }
        
        // ขยับทั้งสอง pointer จน first ถึงท้าย
        while let Some(node) = first.next {
            first = node;
            second = second.next.as_mut().unwrap();
        }
        
        // ลบ node ที่ต้องการ (node ถัดจาก second)
        let to_delete = second.next.take();
        second.next = to_delete.and_then(|node| node.next);
        
        // คืน head ใหม่
        dummy.next
    }
}