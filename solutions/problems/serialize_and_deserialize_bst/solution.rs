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
struct Codec {
	
}

/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Codec {
    fn new() -> Self {
        Codec {}
    }

    fn serialize(&self, root: Option<Rc<RefCell<TreeNode>>>) -> String {
        let mut res = Vec::new();
        Self::preorder(&root, &mut res);

        res.into_iter().map(|v| v.to_string()).collect::<Vec<_>>().join(" ")
    }

    fn preorder(node: &Option<Rc<RefCell<TreeNode>>>, res: &mut Vec<i32>) {
        if let Some(n) = node {
            let borrow = n.borrow();
            res.push(borrow.val);
            Self::preorder(&borrow.left, res);
            Self::preorder(&borrow.right, res);
        }
    }
	
    fn deserialize(&self, data: String) -> Option<Rc<RefCell<TreeNode>>> {
        if data.is_empty() {
            return None;
        }
        let vals: Vec<i32> = data
            .split_whitespace()
            .map(|s| s.parse().unwrap())
            .collect();
        let mut idx = 0;
        Self::build(&vals, &mut idx, i32::MIN, i32::MAX)
    }

    fn build(vals: &[i32], idx: &mut usize, min_val: i32, max_val: i32) -> Option<Rc<RefCell<TreeNode>>> {
        if *idx >= vals.len() {
            return None;
        }
        let val = vals[*idx];
        // ตรวจสอบว่าค่าปัจจุบันอยู่ในช่วงขอบเขตของ BST หรือไม่
        if val < min_val || val > max_val {
            return None;
        }
        *idx += 1;

        let node = Rc::new(RefCell::new(TreeNode::new(val)));
        // ลูกซ้ายค่าต้องน้อยกว่า val ปัจจุบัน (ขอบเขตบนเปลี่ยนเป็น val)
        node.borrow_mut().left = Self::build(vals, idx, min_val, val);
        // ลูกขวาค่าต้องมากกว่า val ปัจจุบัน (ขอบเขตล่างเปลี่ยนเป็น val)
        node.borrow_mut().right = Self::build(vals, idx, val, max_val);
        
        Some(node)
    }
}

/**
 * Your Codec object will be instantiated and called as such:
 * let obj = Codec::new();
 * let data: String = obj.serialize(strs);
 * let ans: Option<Rc<RefCell<TreeNode>>> = obj.deserialize(data);
 */