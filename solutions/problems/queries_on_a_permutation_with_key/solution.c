/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct Node {
    int val;
    struct Node* next;
} Node;

int* processQueries(int* queries, int queriesSize, int m, int* returnSize) {
    *returnSize = queriesSize;
    int* result = (int*)malloc(queriesSize * sizeof(int));
    
    // สร้าง linked list (เรียง 1,2,3,...,m)
    Node* head = NULL;
    for (int i = m; i >= 1; i--) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->val = i;
        newNode->next = head;
        head = newNode;
    }
    
    for (int i = 0; i < queriesSize; i++) {
        int x = queries[i];
        
        // หาตำแหน่งของ x
        Node* prev = NULL;
        Node* curr = head;
        int pos = 0;
        
        while (curr != NULL && curr->val != x) {
            prev = curr;
            curr = curr->next;
            pos++;
        }
        
        result[i] = pos;  // เก็บตำแหน่ง (1-indexed)
        
        // ถ้า x อยู่ที่หัวแล้ว ไม่ต้องย้าย
        if (prev == NULL) {
            continue;
        }
        
        // ลบ node ออกจากตำแหน่งปัจจุบัน
        prev->next = curr->next;
        
        // ย้ายไปหน้าสุด
        curr->next = head;
        head = curr;
    }
    
    // คืนหน่วยความจำของ linked list
    Node* curr = head;
    while (curr != NULL) {
        Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
    
    return result;
}