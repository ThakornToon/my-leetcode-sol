/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node* copyRandomList(struct Node* head) {
    if (!head) return NULL;

    // ขั้นตอนที่ 1: สร้างและแทรกโหนด copy หลังโหนดจริง
    struct Node* curr = head;
    while (curr) {
        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
        copy->val = curr->val;
        copy->next = curr->next;
        copy->random = NULL;

        curr->next = copy;
        curr = copy->next;
    }

    // ขั้นตอนที่ 2: เชื่อม random pointer ของโหนด copy 
    curr = head;
    while (curr) {
        if (curr->random) {
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }

    // ขั้นตอนที่ 3: แยก linked list ทั้งสองชุดออกจากกัน
    struct Node* new_head = head->next;
    curr = head;
    while (curr) {
        struct Node* copy = curr->next;
        curr->next = copy->next;
        copy->next = curr->next ? curr->next->next : NULL;
        curr = curr->next;
    }

    return new_head;
}