int integerReplacement(int n) {
    int steps = 0;
    long long num = n;
    while (num != 1) {
        if (num % 2 == 0) {
            num /= 2;
        } else {
            // เลือกระหว่าง +1 หรือ -1 โดยดู 2 ขั้นต่อไป
            if (num == 3) {
                num--;
            } else if ((num + 1) % 4 == 0) {
                num++;
            } else {
                num--;
            }
        }
        steps++;
    }
    
    return steps;
}