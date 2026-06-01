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
    pub fn level_order(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
        let mut result = Vec::new();
        
        if root.is_none() {
            return result;
        }
        
        let mut queue = VecDeque::new();
        queue.push_back(root);
        
        while !queue.is_empty() {
            let level_size = queue.len();
            let mut current_level = Vec::with_capacity(level_size);
            
            for _ in 0..level_size {
                if let Some(Some(node)) = queue.pop_front() {
                    let borrowed = node.borrow();
                    current_level.push(borrowed.val);
                    
                    if borrowed.left.is_some() {
                        queue.push_back(borrowed.left.clone());
                    }
                    if borrowed.right.is_some() {
                        queue.push_back(borrowed.right.clone());
                    }
                }
            }
            
            result.push(current_level);
        }
        
        result
    }
}