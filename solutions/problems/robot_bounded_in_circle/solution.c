bool isRobotBounded(char* instructions) {
    // Directions: 0 = North, 1 = East, 2 = South, 3 = West
    int dir = 0;
    int x = 0, y = 0;
    
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    for (int i = 0; instructions[i] != '\0'; i++) {
        char c = instructions[i];
        
        if (c == 'G') {
            x += dx[dir];
            y += dy[dir];
        } else if (c == 'L') {
            dir = (dir + 3) % 4; // Turn left (counter-clockwise)
        } else if (c == 'R') {
            dir = (dir + 1) % 4; // Turn right (clockwise)
        }
    }
    
    // ถ้าหุ่นยนต์ไม่ได้หันไปทางเหนือหลังจาก instructions 1 รอบ 
    // ทิศทางจะเปลี่ยนและจะหมุนเป็นวงกลมหรือรูปหลายเหลี่ยม
    // ถ้าหุ่นยนต์ยังหันไปทางเหนือและไม่ได้กลับมาที่ (0,0) จะเดินทางออกไปเรื่อยๆ
    return (x == 0 && y == 0) || (dir != 0);
}