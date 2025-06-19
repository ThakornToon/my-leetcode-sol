int lastRemaining(int n) {
    int left_to_right = 1; // เริ่มจากซ้ายไปขวา (true)
    int remaining = n;
    int step = 1;
    int head = 1;
    
    while (remaining > 1) {
        if (left_to_right || remaining % 2 == 1) {
            head += step;
        }
        
        remaining /= 2;
        step *= 2;
        left_to_right = !left_to_right;
    }
    
    return head;
}