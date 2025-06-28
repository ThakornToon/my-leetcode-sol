#define TABLE_SIZE 10007  // เลขจำนวนเฉพาะเพื่อลดการชนกันของ hash

typedef struct {
    int x, y;
} Point;

typedef struct HashNode {
    Point point;
    struct HashNode* next;
} HashNode;

typedef struct {
    HashNode* table[TABLE_SIZE];
} PointSet;

unsigned int hash(Point p) {
    unsigned long h = 5381;
    h = ((h << 5) + h) + p.x;
    h = ((h << 5) + h) + p.y;
    return h % TABLE_SIZE;
}

void addToSet(PointSet* set, Point p) {
    unsigned int index = hash(p);
    HashNode* current = set->table[index];
    
    // สร้าง node ใหม่
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->point = p;
    newNode->next = set->table[index];
    set->table[index] = newNode;
}

void removeFromSet(PointSet* set, Point p) {
    unsigned int index = hash(p);
    HashNode** ptr = &(set->table[index]);
    
    while (*ptr != NULL) {
        if ((*ptr)->point.x == p.x && (*ptr)->point.y == p.y) {
            HashNode* temp = *ptr;
            *ptr = (*ptr)->next;
            free(temp);
            /*
            table[index] -> A -> B -> C -> NULL
            ให้ *ptr (ซึ่งคือ A->next) ชี้ไปที่ B->next (C)
            ลบ B ออก
            table[index] -> A -> C -> NULL
            */
            
            return;
        }
        ptr = &((*ptr)->next);
    }
}

int isInSet(PointSet* set, Point p) {
    unsigned int index = hash(p);
    HashNode* current = set->table[index];
    
    while (current != NULL) {
        if (current->point.x == p.x && current->point.y == p.y) {
            return 1;
        }
        current = current->next;
    }
    
    return 0;
}

void freeSet(PointSet* set) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        HashNode* current = set->table[i];
        while (current != NULL) {
            HashNode* temp = current;
            current = current->next;
            free(temp);
        }
        set->table[i] = NULL;
    }
}

bool isRectangleCover(int** rectangles, int rectanglesSize, int* rectanglesColSize) {
    if (rectanglesSize == 0) return false;

    int x1 = INT_MAX, y1 = INT_MAX;
    int x2 = INT_MIN, y2 = INT_MIN;
    long long total_area = 0;
    PointSet corner_set;
    for (int i = 0; i < TABLE_SIZE; i++) {
        corner_set.table[i] = NULL;
    }

    for (int i = 0; i < rectanglesSize; i++) {
        int rx1 = rectangles[i][0], ry1 = rectangles[i][1];
        int rx2 = rectangles[i][2], ry2 = rectangles[i][3];

        // Update bounding rectangle
        x1 = rx1 < x1 ? rx1 : x1;
        y1 = ry1 < y1 ? ry1 : y1;
        x2 = rx2 > x2 ? rx2 : x2;
        y2 = ry2 > y2 ? ry2 : y2;

        // Calculate total area
        total_area += (long long)(rx2 - rx1) * (ry2 - ry1);

        // Process corners
        Point corners[4] = {
            {rx1, ry1}, {rx1, ry2}, {rx2, ry1}, {rx2, ry2}
        };

        for (int j = 0; j < 4; j++) {
            if (isInSet(&corner_set, corners[j])) {
                removeFromSet(&corner_set, corners[j]);
            } else {
                addToSet(&corner_set, corners[j]);
            }
        }
    }

    // Check area
    long long bounding_area = (long long)(x2 - x1) * (y2 - y1);
    if (total_area != bounding_area) {
        freeSet(&corner_set);
        return false;
    }

    // Check outer corners
    Point outer_corners[4] = {
        {x1, y1}, {x1, y2}, {x2, y1}, {x2, y2}
    };

    for (int i = 0; i < 4; i++) {
        if (!isInSet(&corner_set, outer_corners[i])) {
            freeSet(&corner_set);
            return false;
        }
    }

    // Verify only 4 corners remain
    int count = 0;
    for (int i = 0; i < TABLE_SIZE; i++) {
        HashNode* current = corner_set.table[i];
        while (current != NULL) {
            count++;
            current = current->next;
        }
    }

    freeSet(&corner_set);
    return count == 4;
}
/* TLE
typedef struct {
    int x, y;
} Point;

typedef struct {
    Point* items;
    int count;
    int capacity;
} PointList;

void createList(PointList* list, int capacity) {
    list->items = (Point*)malloc(capacity * sizeof(Point));
    list->count = 0;
    list->capacity = capacity;
}

int isPointInList(PointList* list, Point p) {
    for (int i = 0; i < list->count; i++) {
        if (list->items[i].x == p.x && list->items[i].y == p.y) {
            return 1;
        }
    }
    return 0;
}

void removePoint(PointList* list, Point p) {
    for (int i = 0; i < list->count; i++) {
        if (list->items[i].x == p.x && list->items[i].y == p.y) {
            // Move last element to current position
            list->items[i] = list->items[list->count - 1];
            list->count--;
            return;
        }
    }
}

void addPoint(PointList* list, Point p) {
    if (isPointInList(list, p)) {
        removePoint(list, p);
    } else {
        
        if (list->count == list->capacity) {
            list->capacity *= 2;
            list->items = (Point*)realloc(list->items, list->capacity * sizeof(Point));
        }
        
        list->items[list->count++] = p;
    }
}

bool isRectangleCover(int** rectangles, int rectanglesSize, int* rectanglesColSize) {
    int x1 = INT_MAX, y1 = INT_MAX;
    int x2 = INT_MIN, y2 = INT_MIN;
    long long total_area = 0;
    PointList corner_list;
    createList(&corner_list, rectanglesSize * 4);

    for (int i = 0; i < rectanglesSize; i++) {
        int rx1 = rectangles[i][0], ry1 = rectangles[i][1];
        int rx2 = rectangles[i][2], ry2 = rectangles[i][3];

        // Update bounding rectangle
        if (rx1 < x1) x1 = rx1;
        if (ry1 < y1) y1 = ry1;
        if (rx2 > x2) x2 = rx2;
        if (ry2 > y2) y2 = ry2;

        // Calculate total area
        total_area += (long long)(rx2 - rx1) * (ry2 - ry1);

        // Check corners
        Point corners[4] = {
            {rx1, ry1}, {rx1, ry2}, {rx2, ry1}, {rx2, ry2}
        };

        for (int j = 0; j < 4; j++) {
            addPoint(&corner_list, corners[j]);
        }
    }

    // Check area
    long long bounding_area = (long long)(x2 - x1) * (y2 - y1);
    if (total_area != bounding_area) {
        free(corner_list.items);
        return false;
    }

    // Check outer corners
    Point outer_corners[4] = {
        {x1, y1}, {x1, y2}, {x2, y1}, {x2, y2}
    };

    for (int i = 0; i < 4; i++) {
        if (!isPointInList(&corner_list, outer_corners[i])) {
            free(corner_list.items);
            return 0;
        }
    }

    bool result = (corner_list.count == 4);
    free(corner_list.items);
    return result;
}

*/