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
    pub fn sum_numbers(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut total = 0;
        Self::dfs(&root, 0, &mut total);
        total
    }

    fn dfs(node: &Option<Rc<RefCell<TreeNode>>>, current_sum: i32, total: &mut i32) {
        if let Some(n) = node {
            let n = n.borrow();
            let current_sum = current_sum * 10 + n.val;
            
            if n.left.is_none() && n.right.is_none() {
                *total += current_sum;
            } else {
                Self::dfs(&n.left, current_sum, total);
                Self::dfs(&n.right, current_sum, total);
            }
        }
    }
}