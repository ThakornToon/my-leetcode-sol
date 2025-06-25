/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    // หาความยาวของ List A
    int lenA = 0;
    struct ListNode *currA = headA;
    while (currA) {
        lenA++;
        currA = currA->next;
    }
    
    // หาความยาวของ List B
    int lenB = 0;
    struct ListNode *currB = headB;
    while (currB) {
        lenB++;
        currB = currB->next;
    }
    
    // ย้าย pointer ของ List ที่ยาวกว่า
    currA = headA;
    currB = headB;
    
    if (lenA > lenB) {
        for (int i = 0; i < lenA - lenB; i++) {
            currA = currA->next;
        }
    } else {
        for (int i = 0; i < lenB - lenA; i++) {
            currB = currB->next;
        }
    }
    
    // หาจุดตัดกัน
    while (currA && currB) {
        if (currA == currB) {
            return currA;
        }
        currA = currA->next;
        currB = currB->next;
    }
    
    return NULL;
}