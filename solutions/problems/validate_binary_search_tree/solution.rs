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
    pub fn is_valid_bst(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        Self::validate(&root, i64::MIN, i64::MAX)
    }

    fn validate(node: &Option<Rc<RefCell<TreeNode>>>, min_val: i64, max_val: i64) -> bool {
        match node {
            None => true,
            Some(node_ref) => {
                // borrow() บน Rc<RefCell<TreeNode>>ได้ Ref<TreeNode>
                let node = node_ref.borrow();
                let val = node.val as i64;
                
                // ตรวจสอบว่า val อยู่ในช่วงที่กำหนด
                if val <= min_val || val >= max_val {
                    return false;
                }
                
                // ตรวจสอบ left และ right subtree
                Self::validate(&node.left, min_val, val) &&
                Self::validate(&node.right, val, max_val)
            }
        }
    }
}