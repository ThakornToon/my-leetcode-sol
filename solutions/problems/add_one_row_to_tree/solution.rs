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
    pub fn add_one_row(root: Option<Rc<RefCell<TreeNode>>>, val: i32, depth: i32) -> Option<Rc<RefCell<TreeNode>>> {
        if depth == 1 {
            let new_root = Rc::new(RefCell::new(TreeNode {
                val,
                left: root,
                right: None,
            }));
            return Some(new_root);
        }

        fn dfs(node: Option<&Rc<RefCell<TreeNode>>>, cur_depth: i32, depth: i32, val: i32) {
            if let Some(n) = node {
                if cur_depth == depth - 1 {
                    let mut b = n.borrow_mut();

                    // ดึงซ้ายขวาออกมา
                    let orig_left = b.left.take();
                    let orig_right = b.right.take();

                    // แทรกโหนดซ้ายขวา
                    let new_left = Rc::new(RefCell::new(TreeNode {
                        val,
                        left: orig_left,
                        right: None,
                    }));
                    let new_right = Rc::new(RefCell::new(TreeNode {
                        val,
                        left: None,
                        right: orig_right,
                    }));

                    b.left = Some(new_left);
                    b.right = Some(new_right);
                } else {
                    let b = n.borrow();

                    dfs(b.left.as_ref(), cur_depth + 1, depth, val);
                    dfs(b.right.as_ref(), cur_depth + 1, depth, val);
                }
            }
        }

        dfs(root.as_ref(), 1, depth, val);
        root
    }
}