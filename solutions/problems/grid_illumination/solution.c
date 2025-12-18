/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define HASH_SIZE 20011  // จำนวนเฉพาะ

typedef struct HashNode {
    long long key;
    int value;
    struct HashNode* next;
} HashNode;

HashNode* rowMap[HASH_SIZE];
HashNode* colMap[HASH_SIZE];
HashNode* diag1Map[HASH_SIZE];  // row - col
HashNode* diag2Map[HASH_SIZE];  // row + col
HashNode* lampPosMap[HASH_SIZE];  // เก็บตำแหน่ง lamps (row,col) → count

// Hash function
int hash(long long key) {
    return (key & 0x7FFFFFFF) % HASH_SIZE;
}

// เพิ่มค่าใน hashmap
void increment(HashNode** map, long long key) {
    int h = hash(key);
    HashNode* node = map[h];
    
    while (node) {
        if (node->key == key) {
            node->value++;
            return;
        }
        node = node->next;
    }
    
    // สร้าง node ใหม่
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->key = key;
    newNode->value = 1;
    newNode->next = map[h];
    map[h] = newNode;
}

// ลดค่าใน hashmap
void decrement(HashNode** map, long long key) {
    int h = hash(key);
    HashNode* node = map[h];
    HashNode* prev = NULL;
    
    while (node) {
        if (node->key == key) {
            node->value--;
            if (node->value <= 0) {
                // ลบ node
                if (prev) prev->next = node->next;
                else map[h] = node->next;
                free(node);
            }
            return;
        }
        prev = node;
        node = node->next;
    }
}

// อ่านค่าจาก hashmap
int get(HashNode** map, long long key) {
    int h = hash(key);
    HashNode* node = map[h];
    
    while (node) {
        if (node->key == key) return node->value;
        node = node->next;
    }
    return 0;
}

// Encode ตำแหน่ง
long long encode(int row, int col) {
    return ((long long)row << 32) | (col & 0xFFFFFFFFLL);
}

int* gridIllumination(int n, int** lamps, int lampsSize, int* lampsColSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    // Initialize hash maps
    for (int i = 0; i < HASH_SIZE; i++) {
        rowMap[i] = colMap[i] = diag1Map[i] = diag2Map[i] = lampPosMap[i] = NULL;
    }
    
    // Add lamps
    for (int i = 0; i < lampsSize; i++) {
        int r = lamps[i][0];
        int c = lamps[i][1];
        long long posKey = encode(r, c);
        
        // เพิ่ม count ในตำแหน่งนี้
        increment(lampPosMap, posKey);
        
        // ถ้าเป็น lamp ใหม่ (count = 1) เพิ่มใน maps อื่น
        if (get(lampPosMap, posKey) == 1) {
            increment(rowMap, r);
            increment(colMap, c);
            increment(diag1Map, r - c);
            increment(diag2Map, r + c);
        }
    }
    
    int* result = (int*)malloc(queriesSize * sizeof(int));
    *returnSize = queriesSize;
    
    int dirs[9][2] = {{0,0},{0,1},{0,-1},{1,0},{1,1},{1,-1},{-1,0},{-1,1},{-1,-1}};
    
    for (int q = 0; q < queriesSize; q++) {
        int r = queries[q][0];
        int c = queries[q][1];
        
        // Check illumination
        int illuminated = 0;
        if (get(rowMap, r) > 0 || get(colMap, c) > 0 ||
            get(diag1Map, r - c) > 0 || get(diag2Map, r + c) > 0) {
            illuminated = 1;
        }
        
        result[q] = illuminated;
        
        // Turn off lamps
        for (int d = 0; d < 9; d++) {
            int nr = r + dirs[d][0];
            int nc = c + dirs[d][1];
            
            if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                long long posKey = encode(nr, nc);
                int lampCount = get(lampPosMap, posKey);
                
                if (lampCount > 0) {
                    // ลบ lamp ทั้งหมดในตำแหน่งนี้
                    decrement(rowMap, nr);
                    decrement(colMap, nc);
                    decrement(diag1Map, nr - nc);
                    decrement(diag2Map, nr + nc);
                    
                    // ลบ lamp positions
                    decrement(lampPosMap, posKey);
                }
            }
        }
    }
    
    return result;

}