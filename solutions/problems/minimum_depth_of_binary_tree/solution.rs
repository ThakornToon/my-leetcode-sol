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
    pub fn min_depth(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        match root {
            None => 0,
            Some(node) => {
                // ใช้ borrow_mut() เพื่อให้ได้ mutable reference แล้วย้าย ownership ของ left/right
                let left = node.borrow_mut().left.take();
                let right = node.borrow_mut().right.take();
                
                match (left, right) {
                    (None, None) => 1,
                    (Some(l), None) => 1 + Self::min_depth(Some(l)),
                    (None, Some(r)) => 1 + Self::min_depth(Some(r)),
                    (Some(l), Some(r)) => {
                        1 + std::cmp::min(Self::min_depth(Some(l)), Self::min_depth(Some(r)))
                    }
                }
            }
        }
    }
}