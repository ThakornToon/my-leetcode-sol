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
    pub fn lowest_common_ancestor(root: Option<Rc<RefCell<TreeNode>>>, p: Option<Rc<RefCell<TreeNode>>>, q: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        let root = match root {
            Some(node) => node,
            None => return None,
        };

        let p_node: &Rc<RefCell<TreeNode>> = p.as_ref().unwrap();
        let q_node: &Rc<RefCell<TreeNode>> = q.as_ref().unwrap();

        // ถ้า Node ปัจจุบันตรงกับ p หรือ q แปลว่าเจอแล้ว (หรือเป็น Ancestor ของอีกตัว) คืนค่า Node นี้กลับไป
        if Rc::ptr_eq(&root, p_node) || Rc::ptr_eq(&root, q_node) {
            return Some(root);
        }

        // ค้นหาใน Subtree ฝั่งซ้ายและขวา
        let left = {
            let borrow = root.borrow();
            Self::lowest_common_ancestor(borrow.left.clone(), Some(p_node.clone()), Some(q_node.clone()))
        };

        let right = {
            let borrow = root.borrow();
            Self::lowest_common_ancestor(borrow.right.clone(), Some(p_node.clone()), Some(q_node.clone()))
        };

        // วิเคราะห์ผลลัพธ์จากซ้ายและขวา
        match (left, right) {
            // ถ้าเจอทั้งซ้ายและขวา แปลว่า p อยู่ฝั่งนึง q อยู่ฝั่งนึง ดังนั้น root ปัจจุบันคือ LCA
            (Some(_), Some(_)) => Some(root),
            // ถ้าเจอฝั่งซ้ายฝั่งเดียว (หรือส่งค่าขึ้นไป) ให้ส่งค่าฝั่งซ้ายขึ้นไปต่อ
            (Some(l), None) => Some(l),
            // ถ้าเจอฝั่งขวาฝั่งเดียว ให้ส่งค่าฝั่งขวาขึ้นไปต่อ
            (None, Some(r)) => Some(r),
            // ถ้าไม่เจอทั้งสองฝั่ง คืนค่า None
            (None, None) => None,
        }
    }
}