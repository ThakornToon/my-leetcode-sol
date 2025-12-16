/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define TABLE_SIZE 10007 
#define MAX_WORD_LEN 8

// โครงสร้าง Hash Map
typedef struct {
    char key[MAX_WORD_LEN];
    char value[MAX_WORD_LEN];
    int occupied;  // 0=ว่าง, 1=ใช้งาน
} HashEntry;

typedef struct {
    HashEntry* entries;
    int size;
} HashMap;

// สร้าง HashMap
HashMap* createHashMap(int size) {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    map->size = size;
    map->entries = (HashEntry*)calloc(size, sizeof(HashEntry));
    return map;
}

// Hash function แบบง่าย
unsigned int hash(const char* key, int size) {
    unsigned int h = 0;
    while (*key) {
        h = (h * 31 + tolower(*key)) % size;
        key++;
    }
    return h % size;
}

// ใส่ค่าลงใน HashMap
void hashPut(HashMap* map, const char* key, const char* value) {
    unsigned int index = hash(key, map->size);
    
    // Linear probing
    while (map->entries[index].occupied) {
        // ถ้ามี key เดิมอยู่แล้ว ไม่ต้องใส่ซ้ำ
        if (strcmp(map->entries[index].key, key) == 0) {
            return;
        }
        index = (index + 1) % map->size;
    }
    
    // ใส่ค่าใหม่
    strcpy(map->entries[index].key, key);
    strcpy(map->entries[index].value, value);
    map->entries[index].occupied = 1;
}

// ดึงค่าจาก HashMap
char* hashGet(HashMap* map, const char* key) {
    unsigned int index = hash(key, map->size);
    int start = index;
    
    while (map->entries[index].occupied) {
        if (strcmp(map->entries[index].key, key) == 0) {
            return map->entries[index].value;
        }
        index = (index + 1) % map->size;
        
        // ตรวจสอบว่าวนกลับมาที่เดิมแล้ว
        if (index == start) break;
    }
    
    return NULL;  // ไม่เจอ
}

// แปลงเป็นตัวพิมพ์เล็ก
void toLowerString(char* dest, const char* src) {
    int i = 0;
    while (src[i]) {
        dest[i] = tolower(src[i]);
        i++;
    }
    dest[i] = '\0';
}

// แทนที่สระด้วย '*'
void devowelString(char* dest, const char* src) {
    int i = 0;
    while (src[i]) {
        char c = tolower(src[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            dest[i] = '*';
        } else {
            dest[i] = c;
        }
        i++;
    }
    dest[i] = '\0';
}

// ฟังก์ชันหลัก spellchecker
char** spellchecker(char** wordlist, int wordlistSize, char** queries, int queriesSize, int* returnSize) {
    *returnSize = queriesSize;
    char** result = (char**)malloc(queriesSize * sizeof(char*));
    
    // สร้าง HashMaps
    HashMap* exactMap = createHashMap(TABLE_SIZE);
    HashMap* caseMap = createHashMap(TABLE_SIZE);
    HashMap* vowelMap = createHashMap(TABLE_SIZE);
    
    char lower[MAX_WORD_LEN];
    char devoweled[MAX_WORD_LEN];
    
    // เตรียมข้อมูลจาก wordlist
    for (int i = 0; i < wordlistSize; i++) {
        char* word = wordlist[i];
        
        // 1. Exact match
        hashPut(exactMap, word, word);
        
        // 2. Case-insensitive match
        toLowerString(lower, word);
        if (hashGet(caseMap, lower) == NULL) {
            hashPut(caseMap, lower, word);
        }
        
        // 3. Vowel-insensitive match
        devowelString(devoweled, word);
        if (hashGet(vowelMap, devoweled) == NULL) {
            hashPut(vowelMap, devoweled, word);
        }
    }
    
    // ตรวจสอบ queries
    for (int i = 0; i < queriesSize; i++) {
        char* query = queries[i];
        char* answer = NULL;
        
        // 1. Exact match
        answer = hashGet(exactMap, query);
        
        if (answer == NULL) {
            // 2. Case-insensitive match
            toLowerString(lower, query);
            answer = hashGet(caseMap, lower);
        }
        
        if (answer == NULL) {
            // 3. Vowel-insensitive match
            devowelString(devoweled, query);
            answer = hashGet(vowelMap, devoweled);
        }
        
        // เก็บผลลัพธ์
        if (answer == NULL) {
            result[i] = (char*)malloc(1);
            result[i][0] = '\0';
        } else {
            result[i] = (char*)malloc(strlen(answer) + 1);
            strcpy(result[i], answer);
        }
    }
    
    free(exactMap->entries);
    free(exactMap);
    free(caseMap->entries);
    free(caseMap);
    free(vowelMap->entries);
    free(vowelMap);
    
    return result;
}