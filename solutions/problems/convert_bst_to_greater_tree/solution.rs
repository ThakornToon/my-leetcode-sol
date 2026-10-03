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
    pub fn convert_bst(root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        let mut sum = 0;

        // Left -> Right -> Root
        fn reverse_inorder(node: Option<&Rc<RefCell<TreeNode>>>, sum: &mut i32) {
            if let Some(n) = node {
                let right = n.borrow().right.clone();
                reverse_inorder(right.as_ref(), sum);

                *sum += n.borrow().val;
                n.borrow_mut().val = *sum;

                let left = n.borrow().left.clone();
                reverse_inorder(left.as_ref(), sum);
            }
        }

        reverse_inorder(root.as_ref(), &mut sum);
        root
    }
}