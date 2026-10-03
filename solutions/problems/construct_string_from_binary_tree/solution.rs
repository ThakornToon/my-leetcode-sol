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
    pub fn tree2str(root: Option<Rc<RefCell<TreeNode>>>) -> String {
        let mut res = String::new();

        fn dfs(node: Option<&Rc<RefCell<TreeNode>>>, res: &mut String) {
            if let Some(n) = node {
                let borrowed = n.borrow();
                res.push_str(&borrowed.val.to_string());

                if borrowed.left.is_some() || borrowed.right.is_some() {
                    res.push('(');
                    dfs(borrowed.left.as_ref(), res);
                    res.push(')');
                }

                if borrowed.right.is_some() {
                    res.push('(');
                    dfs(borrowed.right.as_ref(), res);
                    res.push(')');
                }
            }
        }

        dfs(root.as_ref(), &mut res);
        res
    }
}