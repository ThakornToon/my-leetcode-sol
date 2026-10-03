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
    pub fn search_bst(root: Option<Rc<RefCell<TreeNode>>>, val: i32) -> Option<Rc<RefCell<TreeNode>>> {
        match root {
            None => None, // ถ้าเป็น None (ไม่มีโหนด) ให้คืนค่า None ทันที
            Some(node) => {
                let v = node.borrow().val;

                if v == val {
                    Some(node) // ถ้าเจอค่าที่ตรงกัน คืนค่าโหนดนี้กลับไป
                } else if val < v {
                    Self::search_bst(node.borrow().left.clone(), val) // น้อยกว่า วิ่งไปซ้าย
                } else {
                    Self::search_bst(node.borrow().right.clone(), val) // มากกว่า วิ่งไปขวา
                }
            }
        }
    }
}