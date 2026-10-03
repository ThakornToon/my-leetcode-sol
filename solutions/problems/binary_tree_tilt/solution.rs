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
    pub fn find_tilt(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut total_tilt = 0;

        fn dfs(node: Option<&Rc<RefCell<TreeNode>>>, total_tilt: &mut i32) -> i32 {
            if let Some(n) = node {
                let borrowed = n.borrow();
                let left_sum = dfs(borrowed.left.as_ref(), total_tilt);
                let right_sum = dfs(borrowed.right.as_ref(), total_tilt);

                *total_tilt += (left_sum - right_sum).abs();

                borrowed.val + left_sum + right_sum
            } else {
                0
            }
        }

        dfs(root.as_ref(), &mut total_tilt);
        total_tilt
    }
}