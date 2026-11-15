#define MAX_NODES 3200005 // ขนาดสูงสุดของโหนดที่อาจเกิดขึ้น (numsSize * 32)

typedef struct {
    int children[2];
} TrieNode;

// สร้าง Memory Pool ไว้ล่วงหน้า
TrieNode pool[MAX_NODES];
int pool_count = 0;

int createNode() {
    pool[pool_count].children[0] = 0;
    pool[pool_count].children[1] = 0;
    return pool_count++;  // index โหนดที่พึ่งสร้าง
}

void insert(int root, int num) {
    int curr = root;
    for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (pool[curr].children[bit] == 0) {
            pool[curr].children[bit] = createNode();
        }
        curr = pool[curr].children[bit];
    }
}

int getMaxXor(int root, int num) {
    int curr = root;
    int max_xor = 0;
    
    // พยายาม XOR ให้เป็น 1 โดยพิจารณาบิตสูงก่อน 
    for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        int opposite_bit = 1 - bit;
        
        if (pool[curr].children[opposite_bit] != 0) {
            max_xor |= (1 << i);
            curr = pool[curr].children[opposite_bit];
        } else {
            curr = pool[curr].children[bit];
        }
    }
    return max_xor;
}

int findMaximumXOR(int* nums, int numsSize) {
    pool_count = 0;
    int root = createNode(); // สร้าง Root ไว้ที่ index 0
    
    for (int i = 0; i < numsSize; i++) {
        insert(root, nums[i]);
    }
    
    int max_result = 0;
    for (int i = 0; i < numsSize; i++) {
        int current_xor = getMaxXor(root, nums[i]);
        if (current_xor > max_result) {
            max_result = current_xor;
        }
    }
    
    return max_result;
}