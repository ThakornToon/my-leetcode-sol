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
use std::collections::VecDeque;
impl Solution {
    pub fn max_level_sum(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        // สร้าง queue สำหรับ BFS, unwrap เพราะรู้ว่าไม่ใช่ None
        let mut queue = VecDeque::new();
        queue.push_back(root.unwrap());
        
        let mut max_sum = i32::MIN; 
        let mut max_level = 1;      
        let mut current_level = 1; // ติดตาม level ปัจจุบัน
        
        // BFS 
        while !queue.is_empty() {
            // เก็บจำนวน node ใน level ปัจจุบัน
            let level_size = queue.len();
            let mut level_sum = 0;
            
            // คิดทุก node ใน level นี้
            for _ in 0..level_size {
                // นำ node ออกจาก queue
                let node = queue.pop_front().unwrap();
                // borrow ค่า (Rc<RefCell<TreeNode>> → Ref<TreeNode>)
                let node_ref = node.borrow(); // immutable reference
                
                // เพิ่มค่า node ไปยังผลรวม level
                level_sum += node_ref.val;
                
                // เพิ่ม children เข้า queue ถ้ามี
                if let Some(left) = &node_ref.left {
                    // node_ref.left เป็น Option<Rc<RefCell<TreeNode>>>
                    // &node_ref.left ได้ &Option<Rc<...>>
                    // left เป็น &Rc<RefCell<TreeNode>>
                    // clone Rc pointer (เพิ่ม reference count)
                    queue.push_back(left.clone());
                }
                if let Some(right) = &node_ref.right {
                    queue.push_back(right.clone());
                }
            }
            
            // เปรียบเทียบกับค่าสูงสุด
            if level_sum > max_sum {
                max_sum = level_sum;
                max_level = current_level;
            }
            
            // ไป level ถัดไป
            current_level += 1;
        }
        
        max_level
    }
}