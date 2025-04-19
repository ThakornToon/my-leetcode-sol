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
    pub fn add_two_numbers(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut sum = 0;
        let mut carry = 0;
        let mut l3 = Some(Box::new(ListNode {val:0, next:None} ));
        let mut l4 = l3.as_mut(); //ไม่ย้ายเจ้าของ
        let mut l1 = l1.as_ref(); //ไม่ย้ายเจ้าของ
        let mut l2 = l2.as_ref();

        while l1.is_some() || l2.is_some(){
            sum=0;
            if let Some(node) = l1{
                sum += node.val;
                l1 = node.next.as_ref();
            }
            if let Some(node) = l2{
                sum += node.val;
                l2 = node.next.as_ref(); //ไม่ย้ายเจ้าของ ไม่งั้น node.next จะกลายเป็น None
            }
            sum+=carry;
            carry = sum/10;
            sum%=10;
            l4.as_mut().unwrap().next = Some(Box::new(ListNode {val:sum, next:None} )); //as_mut ทำให้ l4 ยังใช้ได้หลัง unwrap ซึ่งปกติจะ consume ค่านั้น
            l4 = l4.unwrap().next.as_mut(); //as_mut เพื่อเป็นการ ref mut ไปที่ next 
        }
        if carry!=0{
            l4.unwrap().next = Some(Box::new(ListNode {val:carry, next:None} ));
        }
        
        return l3.unwrap().next;
    }
}