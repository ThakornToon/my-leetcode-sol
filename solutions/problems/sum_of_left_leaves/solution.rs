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
    pub fn sum_of_left_leaves(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        Self::dfs(&root, false)
    }

    fn dfs(node: &Option<Rc<RefCell<TreeNode>>>, is_left: bool) -> i32 {
        match node {
            None => 0,
            Some(n) => {
                let borrow = n.borrow();
                
                // ตรวจสอบว่าเป็น Leaf Node หรือไม่ (ไม่มีลูกทั้งซ้ายและขวา)
                if borrow.left.is_none() && borrow.right.is_none() {
                    // ถ้าเป็น Leaf และถูกส่งมาทางฝั่งซ้าย (is_left = true) ให้คืนค่าตัวเลข
                    return if is_left { borrow.val } else { 0 };
                }

                // เดินสำรวจต่อ: ลูกซ้ายส่งสถานะ is_left = true, ลูกขวาส่ง is_left = false
                Self::dfs(&borrow.left, true) + Self::dfs(&borrow.right, false)
            }
        }
    }
}