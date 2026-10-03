// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn merge_trees(root1: Option<Rc<RefCell<TreeNode>>>, root2: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        match (root1, root2) {
            (None, None) => None,
            (Some(node1), None) => Some(node1),
            (None, Some(node2)) => Some(node2),
            (Some(node1), Some(node2)) => {
                // อัปเดตค่า และดึงลูกซ้าย-ขวาของ node1 ออกมา (b1, b2 จะถูก drop ทันทีที่จบปีกกา)
                let (l1, r1) = {
                    let mut b1 = node1.borrow_mut();
                    let b2 = node2.borrow();
                    b1.val += b2.val;
                    (b1.left.take(), b1.right.take())
                };

                // ดึงลูกซ้าย-ขวาของ node2 (b2 จะถูก drop ทันทีที่จบปีกกา)
                let (l2, r2) = {
                    let b2 = node2.borrow();
                    (b2.left.clone(), b2.right.clone())
                };

                // เรียก Recursion นอกบล็อกการยืม
                let merged_left = Self::merge_trees(l1, l2);
                let merged_right = Self::merge_trees(r1, r2);

                // บล็อกที่ 3: นำผลลัพธ์ที่รวมแล้วใส่กลับเข้าไปใน node1
                {
                    let mut b1 = node1.borrow_mut();
                    b1.left = merged_left;
                    b1.right = merged_right;
                } // b1 หลุดพ้นขอบเขตและถูก drop ที่นี่

                // ตอนนี้ node1 เป็นอิสระจากการยืมแล้ว สามารถย้ายสิทธิ์ส่งออกไปได้ทันที
                Some(node1)
            }
        }
    }
}