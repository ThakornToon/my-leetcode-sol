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
    pub fn is_symmetric(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        match root {
            None => true,
            Some(node) => {
                let borrowed = node.borrow();
                Self::is_mirror(borrowed.left.clone(), borrowed.right.clone())
            }
        }
    }
    
    fn is_mirror(
        left: Option<Rc<RefCell<TreeNode>>>,
        right: Option<Rc<RefCell<TreeNode>>>,
    ) -> bool {
        match (left, right) {
            // ทั้งคู่เป็น None
            (None, None) => true,
            
            // มีค่าและสามารถเปรียบเทียบได้
            (Some(l), Some(r)) => {
                let l_borrowed = l.borrow();
                let r_borrowed = r.borrow();
                
                l_borrowed.val == r_borrowed.val &&
                Self::is_mirror(l_borrowed.left.clone(), r_borrowed.right.clone()) &&
                Self::is_mirror(l_borrowed.right.clone(), r_borrowed.left.clone())
            }
            
            // กรณีอื่นๆ (อันหนึ่งเป็น None อีกอันไม่ใช่)
            _ => false,
        }
    }
}