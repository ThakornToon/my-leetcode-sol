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
    pub fn longest_univalue_path(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut max_len = 0;

        fn dfs(node: Option<&Rc<RefCell<TreeNode>>>, max_len: &mut i32) -> i32 {
            if let Some(n) = node {
                let b = n.borrow();
                let left_path = dfs(b.left.as_ref(), max_len);
                let right_path = dfs(b.right.as_ref(), max_len);

                let mut left_extend = 0;
                let mut right_extend = 0;

                if let Some(left_child) = &b.left {
                    if left_child.borrow().val == b.val {
                        left_extend = left_path + 1;
                    }
                }
                if let Some(right_child) = &b.right {
                    if right_child.borrow().val == b.val {
                        right_extend = right_path + 1;
                    }
                }

                *max_len = std::cmp::max(*max_len, left_extend + right_extend);
                std::cmp::max(left_extend, right_extend)
            } else {
                0
            }
        }

        dfs(root.as_ref(), &mut max_len);
        max_len
    }
}