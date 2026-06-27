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
    fn dfs(root: Option<Rc<RefCell<TreeNode>>>, result: &mut Vec<Vec<i32>>, level: usize) {
        if let Some(node) = root {
            let node_ref = node.borrow();
            
            // ถ้า level นี้ยังไม่มี ให้เพิ่ม
            if level == result.len() {
                result.push(Vec::new());
            }
            
            result[level].push(node_ref.val);
            
            Self::dfs(node_ref.left.clone(), result, level + 1);
            Self::dfs(node_ref.right.clone(), result, level + 1);
        }
    }
    
    pub fn level_order_bottom(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
        let mut result = Vec::new();
        Self::dfs(root, &mut result, 0);
        result.reverse();
        result
    }
}