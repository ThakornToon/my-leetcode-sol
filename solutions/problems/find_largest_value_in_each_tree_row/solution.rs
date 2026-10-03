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
    pub fn largest_values(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut result = Vec::new();
        let root = match root {
            Some(node) => node,
            None => return result,
        };

        let mut queue = VecDeque::new();
        queue.push_back(root);

        while !queue.is_empty() {
            let level_size = queue.len();
            let mut max_val = i32::MIN;

            for _ in 0..level_size {
                if let Some(node) = queue.pop_front() {
                    let borrowed = node.borrow();
                    max_val = std::cmp::max(max_val, borrowed.val);

                    if let Some(left) = borrowed.left.clone() {
                        queue.push_back(left);
                    }
                    if let Some(right) = borrowed.right.clone() {
                        queue.push_back(right);
                    }
                }
            }

            result.push(max_val);
        }

        result
    }
}