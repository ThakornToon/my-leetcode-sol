#define MAX_STATES 720 // 6! = 720 states สูงสุด

typedef struct {
    char state[7]; // "123450" + null terminator
    int moves;
} State;

// ฟังก์ชันตรวจสอบว่า state นี้เคยเห็นแล้วหรือไม่
int is_visited(char visited[720][7], int count, char* state) {
    for (int i = 0; i < count; i++) {
        if (strcmp(visited[i], state) == 0) {
            return 1; // พบแล้ว
        }
    }
    return 0; // ไม่พบ
}

int slidingPuzzle(int** board, int boardSize, int* boardColSize) {
    char target[] = "123450";
    char start[7] = {0};
    
    // แปลงบอร์ดเป็น string
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            start[i * 3 + j] = board[i][j] + '0';
        }
    }
    start[6] = '\0';
    
    // BFS queues
    State queue[MAX_STATES];
    int front = 0, rear = 0;
    
    // visited states (เก็บเป็น array ของ string)
    char visited[MAX_STATES][7];
    int visited_count = 0;
    
    // เพิ่ม state เริ่มต้น
    strcpy(queue[rear].state, start);
    queue[rear].moves = 0;
    strcpy(visited[visited_count++], start);
    rear++;
    
    // ทิศทางการเลื่อน (ขึ้น, ขวา, ลง, ซ้าย)
    int directions[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    while (front < rear) {
        State current = queue[front++];
        
        // ตรวจสอบว่าเจอ target แล้วหรือยัง
        if (strcmp(current.state, target) == 0) {
            return current.moves;
        }
        
        // หาตำแหน่งช่องว่าง (0)
        int zero_pos = -1;
        for (int i = 0; i < 6; i++) {
            if (current.state[i] == '0') {
                zero_pos = i;
                break;
            }
        }
        
        int row = zero_pos / 3;
        int col = zero_pos % 3;
        
        // ลองเลื่อนทั้ง 4 ทิศทาง
        for (int d = 0; d < 4; d++) {
            int new_row = row + directions[d][0];
            int new_col = col + directions[d][1];
            
            // ตรวจสอบขอบเขต
            if (new_row >= 0 && new_row < 2 && new_col >= 0 && new_col < 3) {
                int new_pos = new_row * 3 + new_col;
                
                // สร้าง state ใหม่โดยสลับช่องว่างกับตัวเลขที่อยู่ติดกัน
                char next_state[7];
                strcpy(next_state, current.state);
                
                // สลับตัวอักษร
                char temp = next_state[zero_pos];
                next_state[zero_pos] = next_state[new_pos];
                next_state[new_pos] = temp;
                
                // ตรวจสอบว่า state นี้ยังไม่เคยเห็น
                if (!is_visited(visited, visited_count, next_state)) {
                    // เพิ่มเข้า queue
                    strcpy(queue[rear].state, next_state);
                    queue[rear].moves = current.moves + 1;
                    rear++;
                    
                    // ทำเครื่องหมายว่าเคยเห็นแล้ว
                    strcpy(visited[visited_count++], next_state);
                }
            }
        }
    }
    
    return -1; // ไม่พบทางไป target
}