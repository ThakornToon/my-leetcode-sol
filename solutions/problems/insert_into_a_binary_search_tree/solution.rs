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
    pub fn insert_into_bst(root: Option<Rc<RefCell<TreeNode>>>, val: i32) -> Option<Rc<RefCell<TreeNode>>> {
        let node = match root {
            Some(n) => {
                {
                    let mut b = n.borrow_mut();
                    if val < b.val {
                        // ดึงทางซ้ายมาแก้ไขก่อนใส่กลับไปใหม่
                        let left : Option<Rc<RefCell<TreeNode>>> = b.left.take();
                        b.left = Self::insert_into_bst(left, val);
                    } else {
                        // ดึงทางขวามาแก้ไขก่อนใส่กลับไปใหม่
                        let right : Option<Rc<RefCell<TreeNode>>> = b.right.take();
                        b.right = Self::insert_into_bst(right, val);
                    }
                }
                // หมด scope แล้ว b จะไม่ได้ borrow n แล้ว
                n
            }
            None => Rc::new(RefCell::new(TreeNode::new(val))),
        };
        Some(node)
    }
}