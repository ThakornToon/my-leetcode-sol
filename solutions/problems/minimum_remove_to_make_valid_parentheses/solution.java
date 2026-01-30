class Solution {
    public String minRemoveToMakeValid(String s) {
        int n = s.length();
        Stack<Integer> stack = new Stack<>();
        boolean[] remove = new boolean[n];
        
        // 1. ตรวจสอบ parentheses
        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            if (c == '(') {
                stack.push(i);
            } else if (c == ')') {
                if (!stack.isEmpty()) {
                    stack.pop();  // มี '(' คู่กัน
                } else {
                    remove[i] = true;  // ')' ที่ไม่มีคู่
                }
            }
        }
        
        // 2. '(' ที่เหลือใน stack ต้องลบ
        while (!stack.isEmpty()) {
            remove[stack.pop()] = true;
        }
        
        // 3. สร้าง string ผลลัพธ์
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < n; i++) {
            if (!remove[i]) {
                result.append(s.charAt(i));
            }
        }
        
        return result.toString();
    }
}