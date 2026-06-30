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
use std::collections::VecDeque;
impl Solution {
    pub fn right_side_view(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut result = Vec::new();
        if root.is_none() {
            return result;
        }
        
        let mut queue = VecDeque::new();
        queue.push_back(root);
        
        while !queue.is_empty() {
            let level_size = queue.len();
            let mut rightmost = 0;
            
            // วนลูปทุก node ใน level นี้
            for i in 0..level_size {
                if let Some(Some(node)) = queue.pop_front() {
                    let node_ref = node.borrow();
                    rightmost = node_ref.val;
                    
                    // เพิ่ม children (left ก่อน แล้ว right)
                    if let Some(left) = node_ref.left.clone() {
                        queue.push_back(Some(left));
                    }
                    if let Some(right) = node_ref.right.clone() {
                        queue.push_back(Some(right));
                    }
                }
            }
            
            result.push(rightmost);
        }
        
        result
    }
}