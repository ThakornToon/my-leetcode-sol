#define MAX_POINTS 40000
#define HASH_SIZE 40001

typedef struct {
    int x;
    int y;
} Point;

typedef struct Node {
    Point point;
    struct Node* next;
} Node;

// Hash function สำหรับ point
unsigned int hashPoint(int x, int y) {
    return ((unsigned int)x * 31 + (unsigned int)y) % HASH_SIZE;
}

// เพิ่ม point ลง hash table
void addPoint(Node** hashTable, int x, int y) {
    unsigned int index = hashPoint(x, y);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->point.x = x;
    newNode->point.y = y;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

// ตรวจสอบว่า point อยู่ใน hash table หรือไม่
bool containsPoint(Node** hashTable, int x, int y) {
    unsigned int index = hashPoint(x, y);
    Node* current = hashTable[index];
    
    while (current != NULL) {
        if (current->point.x == x && current->point.y == y) {
            return true;
        }
        current = current->next;
    }
    return false;
}

int minAreaRect(int** points, int pointsSize, int* pointsColSize) {
    // สร้าง hash table สำหรับเก็บจุดทั้งหมด
    Node* hashTable[HASH_SIZE] = {0};
    
    // เก็บจุดลง hash table
    for (int i = 0; i < pointsSize; i++) {
        addPoint(hashTable, points[i][0], points[i][1]);
    }
    
    int minArea = INT_MAX;
    
    // ตรวจสอบทุกคู่ของจุดที่เป็นแนวทแยง
    for (int i = 0; i < pointsSize; i++) {
        int x1 = points[i][0];
        int y1 = points[i][1];
        
        for (int j = i + 1; j < pointsSize; j++) {
            int x2 = points[j][0];
            int y2 = points[j][1];
            
            // ตรวจสอบว่าเป็นแนวทแยงของสี่เหลี่ยมผืนผ้าหรือไม่ (x1 != x2 และ y1 != y2)
            if (x1 != x2 && y1 != y2) {
                // ตรวจสอบว่ามีจุด (x1, y2) และ (x2, y1) หรือไม่
                if (containsPoint(hashTable, x1, y2) && containsPoint(hashTable, x2, y1)) {
                    int area = abs(x2 - x1) * abs(y2 - y1);
                    if (area > 0 && area < minArea) {
                        minArea = area;
                    }
                }
            }
        }
    }
    
    // คืนค่าพื้นที่หรือ 0 ถ้าไม่พบสี่เหลี่ยมผืนผ้า
    return (minArea == INT_MAX) ? 0 : minArea;
}