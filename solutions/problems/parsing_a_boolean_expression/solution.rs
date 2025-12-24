impl Solution {
    pub fn parse_bool_expr(expression: String) -> bool {
        let mut stack: Vec<char> = Vec::new();
        
        for c in expression.chars() {
            if c == ',' {
                continue;
            }
            
            if c == ')' {
                // ดึง operand ทั้งหมด
                let mut operands: Vec<bool> = Vec::new();
                while let Some(top) = stack.pop() {
                    if top == '(' {
                        break;
                    }
                    match top {
                        't' => operands.push(true),
                        'f' => operands.push(false),
                        _ => {} // ไม่ควรมีอย่างอื่น
                    }
                }
                
                // ดึง operator
                let op = stack.pop().unwrap();
                
                // ประเมินผล
                let result = match op {
                    '!' => !operands[0],
                    '&' => operands.iter().all(|&x| x),
                    '|' => operands.iter().any(|&x| x),
                    _ => false, // ไม่ควรเกิดขึ้น
                };
                
                // เก็บผลลัพธ์กลับ
                stack.push(if result { 't' } else { 'f' });
            } else {
                stack.push(c);
            }
        }
        
        stack[0] == 't'
    }
}