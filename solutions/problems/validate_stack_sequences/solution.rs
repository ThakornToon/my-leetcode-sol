impl Solution {
    pub fn validate_stack_sequences(pushed: Vec<i32>, popped: Vec<i32>) -> bool {
        let mut stack = Vec::new();
        let mut push_idx = 0;
        
        for &target in &popped {
            // push จนกว่าจะเจอ target ที่ top ของ stack
            while stack.is_empty() || *stack.last().unwrap() != target {
                if push_idx >= pushed.len() {
                    return false;
                }
                stack.push(pushed[push_idx]);
                push_idx += 1;
            }
            
            // pop target
            stack.pop();
        }
        
        stack.is_empty()
    }
}