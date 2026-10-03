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
    pub fn is_subtree(root: Option<Rc<RefCell<TreeNode>>>, sub_root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        

        fn is_same_tree(
            p: Option<&Rc<RefCell<TreeNode>>>,
            q: Option<&Rc<RefCell<TreeNode>>>,
        ) -> bool {
            match (p, q) {
                (None, None) => true,
                (Some(p_node), Some(q_node)) => {
                    let p_b = p_node.borrow();
                    let q_b = q_node.borrow();
                    p_b.val == q_b.val
                        && is_same_tree(p_b.left.as_ref(), q_b.left.as_ref())
                        && is_same_tree(p_b.right.as_ref(), q_b.right.as_ref())
                }
                _ => false,
            }
        }


        fn dfs(
            root: Option<&Rc<RefCell<TreeNode>>>,
            sub_root: Option<&Rc<RefCell<TreeNode>>>,
        ) -> bool {
            match root {
                None => false,
                Some(node) => {
                    if is_same_tree(Some(node), sub_root) {
                        return true;
                    }
                    let borrowed = node.borrow();
                    dfs(borrowed.left.as_ref(), sub_root)
                        || dfs(borrowed.right.as_ref(), sub_root)
                }
            }
        }


        dfs(root.as_ref(), sub_root.as_ref())
    }
}