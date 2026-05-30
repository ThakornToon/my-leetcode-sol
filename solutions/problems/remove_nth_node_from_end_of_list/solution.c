/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    // สร้าง dummy node ช่วยให้จัดการกรณีลบ head ได้ง่าย
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = head;
    
    // ใช้ two pointers: first และ second
    struct ListNode* first = dummy;
    struct ListNode* second = dummy;
    
    // ขยับ first ไปข้างหน้า n+1 steps
    // เพื่อให้ห่างจาก second อยู่ n โหนด
    for (int i = 0; i <= n; i++) {
        first = first->next;
    }
    
    // ขยับทั้งสอง pointer พร้อมกันจน first ถึงท้าย
    while (first != NULL) {
        first = first->next;
        second = second->next;
    }
    
    // ตอนนี้ second ชี้ไปที่โหนดก่อนหน้าโหนดที่จะลบ
    struct ListNode* toDelete = second->next;
    second->next = toDelete->next;
    free(toDelete);
    
    // คืน head ใหม่
    struct ListNode* newHead = dummy->next;
    free(dummy);
    return newHead;
}