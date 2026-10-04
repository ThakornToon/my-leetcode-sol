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
    pub fn delete_node(root: Option<Rc<RefCell<TreeNode>>>, key: i32) -> Option<Rc<RefCell<TreeNode>>> {
        match root {
            None => None,
            Some(node) => {
                let val = node.borrow().val;
                
                if key < val {
                    let left = node.borrow_mut().left.take();
                    node.borrow_mut().left = Self::delete_node(left, key);
                } else if key > val {
                    let right = node.borrow_mut().right.take();
                    node.borrow_mut().right = Self::delete_node(right, key);
                } else {
                    // ดึงลูกซ้ายและขวาออกมาเพื่อเช็คและจัดการ
                    let left = node.borrow_mut().left.take();
                    let right = node.borrow_mut().right.take();

                    if left.is_none() {
                        return right;
                    }
                    if right.is_none() {
                        return left;
                    }

                    // หาค่าน้อยที่สุดจาก Subtree ฝั่งขวา (Inorder Successor)
                    let mut curr: Rc<RefCell<TreeNode>> = right.as_ref().unwrap().clone();
                    loop {
                        let next_left = {
                            let borrow = curr.borrow();
                            match borrow.left.as_ref() {
                                Some(left_node) => left_node.clone(),
                                None => break,
                            }
                        };
                        curr = next_left;
                    }

                    let min_val = curr.borrow().val;
                    
                    // อัปเดตค่าและเชื่อมต่อโครงสร้างใหม่
                    node.borrow_mut().val = min_val;
                    node.borrow_mut().left = left;
                    node.borrow_mut().right = Self::delete_node(Some(right.unwrap()), min_val);
                }
                
                Some(node)
            }
        }
    }
}