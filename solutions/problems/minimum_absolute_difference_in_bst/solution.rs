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
    pub fn get_minimum_difference(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut prev_val: Option<i32> = None;
        let mut min_diff = i32::MAX;

        fn inorder(
            node: Option<&Rc<RefCell<TreeNode>>>,
            prev_val: &mut Option<i32>,
            min_diff: &mut i32,
        ) {
            if let Some(n) = node {
                let borrowed = n.borrow();
                inorder(borrowed.left.as_ref(), prev_val, min_diff);

                if let Some(prev) = *prev_val {
                    *min_diff = std::cmp::min(*min_diff, borrowed.val - prev);
                }
                *prev_val = Some(borrowed.val);

                inorder(borrowed.right.as_ref(), prev_val, min_diff);
            }
        }

        inorder(root.as_ref(), &mut prev_val, &mut min_diff);
        min_diff
    }
}