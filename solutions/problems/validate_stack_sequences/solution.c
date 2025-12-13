bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize) {
    int stackTop = -1;  // ใช้ pushed array เป็น stack
    int pushIndex = 0;
    
    for (int i = 0; i < poppedSize; i++) {
        int target = popped[i];
        
        // ถ้า top ของ stack (ใน pushed array) ไม่ใช่ target
        // ให้ push ต่อไป
        while (stackTop == -1 || pushed[stackTop] != target) {
            if (pushIndex >= pushedSize) {
                return false;
            }
            
            // push: เก็บค่าในตำแหน่งถัดไป
            stackTop++;
            pushed[stackTop] = pushed[pushIndex];
            pushIndex++;
        }
        
        // pop: ลด stack top
        stackTop--;
    }
    
    return stackTop == -1;
}