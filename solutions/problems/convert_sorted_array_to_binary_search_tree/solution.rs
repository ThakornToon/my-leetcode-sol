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
    fn build_bst(nums: &[i32]) -> Option<Rc<RefCell<TreeNode>>> {
        if nums.is_empty() {
            return None;
        }
        
        let mid = nums.len() / 2;
        
        // สร้าง root node
        let root = Rc::new(RefCell::new(TreeNode::new(nums[mid])));
        
        // สร้าง subtree ซ้ายและขวา
        root.borrow_mut().left = Self::build_bst(&nums[..mid]);
        root.borrow_mut().right = Self::build_bst(&nums[mid + 1..]);
        
        Some(root)
    }

    pub fn sorted_array_to_bst(nums: Vec<i32>) -> Option<Rc<RefCell<TreeNode>>> {
        Self::build_bst(&nums)
    }
}