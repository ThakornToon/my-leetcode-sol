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
        let p_val = match p.as_ref() {
            Some(node) => node.borrow().val,
            None => return None,
        };
        let q_val = match q.as_ref() {
            Some(node) => node.borrow().val,
            None => return None,
        };

        let mut curr = root;
        
        // วนลูปเดินหาจุดแยก (LCA) ตามคุณสมบัติของ BST
        while let Some(node) = curr.clone() {
            let root_val = node.borrow().val;

            if p_val < root_val && q_val < root_val {
                // ถ้าค่าน้อยกว่าทั้งคู่ แปลว่า LCA อยู่ฝั่งซ้าย
                curr = node.borrow().left.clone();
            } else if p_val > root_val && q_val > root_val {
                // ถ้าค่ามากกว่าทั้งคู่ แปลว่า LCA อยู่ฝั่งขวา
                curr = node.borrow().right.clone();
            } else {
                // ถ้าค่าแยกฝั่งกัน หรือตัวใดตัวหนึ่งเท่ากับ Node ปัจจุบัน แปลว่าเจอ LCA แล้ว
                return Some(node);
            }
        }

        None
    }
}