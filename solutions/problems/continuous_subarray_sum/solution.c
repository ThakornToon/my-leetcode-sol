#define HASH_SIZE 10007

typedef struct HashNode {
    int key;
    int value;
    struct HashNode* next;
} HashNode;

typedef struct {
    HashNode* buckets[HASH_SIZE];
} HashMap;

HashMap* createHashMap() {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    for (int i = 0; i < HASH_SIZE; i++) {
        map->buckets[i] = NULL;
    }
    return map;
}

int hash(int key, int size) {
    return (key % size + size) % size;
}

void put(HashMap* map, int key, int value) {
    int index = hash(key, HASH_SIZE);
    
    HashNode* current = map->buckets[index];
    while (current != NULL) {
        if (current->key == key) {
            return; // Key already exists
        }
        current = current->next;
    }
    
    // Insert new node
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->key = key;
    newNode->value = value;
    newNode->next = map->buckets[index];
    map->buckets[index] = newNode;
}

int get(HashMap* map, int key) {
    int index = hash(key, HASH_SIZE);
    
    HashNode* current = map->buckets[index];
    while (current != NULL) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    return -2; // Not found
}

void freeHashMap(HashMap* map) {
    for (int i = 0; i < HASH_SIZE; i++) {
        HashNode* current = map->buckets[i];
        while (current != NULL) {
            HashNode* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(map);
}

bool checkSubarraySum(int* nums, int numsSize, int k) {
    if (numsSize < 2) return false;
    
    HashMap* map = createHashMap();
    put(map, 0, -1); // Important initialization
    
    int prefixSum = 0;
    
    for (int i = 0; i < numsSize; i++) {
        prefixSum += nums[i];
        int remainder = prefixSum % k;
        
        if (remainder < 0) {
            remainder += k;
        }
        
        int prevIndex = get(map, remainder);
        if (prevIndex != -2) {
            if (i - prevIndex >= 2) {
                freeHashMap(map);
                return true;
            }
        } else {
            put(map, remainder, i);
        }
    }
    
    freeHashMap(map);
    return false;
}
