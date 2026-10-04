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
        Self::preorder_serialize(&root, &mut res);
        res.join(",")
    }

    fn preorder_serialize(node: &Option<Rc<RefCell<TreeNode>>>, res: &mut Vec<String>) {
        match node {
            None => res.push("null".to_string()),
            Some(n) => {
                let borrow = n.borrow();
                res.push(borrow.val.to_string());
                Self::preorder_serialize(&borrow.left, res);
                Self::preorder_serialize(&borrow.right, res);
            }
        }
    }
	
    fn deserialize(&self, data: String) -> Option<Rc<RefCell<TreeNode>>> {
        if data.is_empty() {
            return None;
        }
        let vals: Vec<&str> = data.split(',').collect();
        let mut idx = 0;
        Self::preorder_deserialize(&vals, &mut idx)
    }

    fn preorder_deserialize(vals: &[&str], idx: &mut usize) -> Option<Rc<RefCell<TreeNode>>> {
        if *idx >= vals.len() || vals[*idx] == "null" {
            *idx += 1;
            return None;
        }

        let val: i32 = vals[*idx].parse().unwrap();
        *idx += 1;

        let node = Rc::new(RefCell::new(TreeNode::new(val)));
        node.borrow_mut().left = Self::preorder_deserialize(vals, idx);
        node.borrow_mut().right = Self::preorder_deserialize(vals, idx);

        Some(node)
    }
}

/**
 * Your Codec object will be instantiated and called as such:
 * let obj = Codec::new();
 * let data: String = obj.serialize(strs);
 * let ans: Option<Rc<RefCell<TreeNode>>> = obj.deserialize(data);
 */