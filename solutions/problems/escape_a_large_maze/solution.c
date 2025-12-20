/*
1 ล้าน = 10^6 -> r * c = 10^12 เป็นไปไม่ได้ที่จะค้นหาแบบ DFS/BFS ทั่วทั้งตาราง
มีเซลล์ที่ถูกบล็อกได้สูงสุด 200 เซลล์
หากเซลล์ที่ถูกบล็อกอยู่ติดกัน พวกมันสามารถล้อมรอบพื้นที่ได้
พื้นที่ที่ถูกล้อมรอบมีขนาดจำกัด (เนื่องจากมีจำนวนเซลล์ที่ถูกบล็อกจำกัด)
พื้นที่ที่ใหญ่ที่สุดที่สามารถล้อมรอบได้คือพื้นที่รูปสามเหลี่ยม
*/

#define MAX_BFS 20000  // 20,000 nodes maximum
#define HASH_SIZE 2000003  // Prime number for hash table

typedef struct {
    int x;
    int y;
} Point;

typedef struct Node {
    Point p;
    struct Node* next;
} Node;

Node* hashTable[HASH_SIZE];

unsigned int hash(Point p) {
    return ((unsigned int)p.x * 31 + (unsigned int)p.y) % HASH_SIZE;
}

bool contains(Point p) {
    unsigned int h = hash(p);
    Node* curr = hashTable[h];
    while (curr != NULL) {
        if (curr->p.x == p.x && curr->p.y == p.y) {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

void insert(Point p) {
    unsigned int h = hash(p);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->p = p;
    newNode->next = hashTable[h];
    hashTable[h] = newNode;
}

bool isEscapePossible(int** blocked, int blockedSize, int* blockedColSize, int* source, int sourceSize, int* target, int targetSize) {
    memset(hashTable, 0, sizeof(hashTable));
    
    Point src = {source[0], source[1]};
    Point tgt = {target[0], target[1]};
    
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    // BFS from source
    bool bfs(Point start, Point end) {
        memset(hashTable, 0, sizeof(hashTable)); // visited
        // Add blocked cells to hash table
        for (int i = 0; i < blockedSize; i++) {
            Point p = {blocked[i][0], blocked[i][1]};
            insert(p);
        }
        Point* queue = (Point*)malloc(MAX_BFS * sizeof(Point));
        int front = 0, rear = 0;
        
        queue[rear++] = start;
        insert(start);
        
        int visitedCount = 0;
        
        while (front < rear) {
            Point curr = queue[front++];
            visitedCount++;
            
            // If visited enough cells, we can escape
            if (visitedCount > MAX_BFS) {
                free(queue);
                return true;
            }
            
            // If reached target
            if (curr.x == end.x && curr.y == end.y) {
                free(queue);
                return true;
            }
            
            // Explore neighbors
            for (int i = 0; i < 4; i++) {
                int nx = curr.x + dirs[i][0];
                int ny = curr.y + dirs[i][1];
                
                // Check bounds
                if (nx < 0 || nx >= 1000000 || ny < 0 || ny >= 1000000) {
                    continue;
                }
                
                Point next = {nx, ny};
                
                // Check if blocked or visited
                if (contains(next)) {
                    continue;
                }
                
                // Mark as visited and add to queue
                insert(next);
                queue[rear++] = next;
                
                if (rear >= MAX_BFS) {
                    free(queue);
                    return true; // Exceeded limit
                }
            }
        }
        
        free(queue);
        return false;
    }

    bool res = bfs(src, tgt) && bfs(tgt, src);

    for (int i = 0; i < HASH_SIZE; i++) {
        Node* curr = hashTable[i];
        while (curr != NULL) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
        hashTable[i] = NULL;
    }

    return res;
}