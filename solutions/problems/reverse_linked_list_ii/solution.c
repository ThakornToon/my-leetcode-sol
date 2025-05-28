/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (!head || left == right) {
        return head;
    }

    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;
    for (int i = 0; i < left - 1; i++) { //หาโหนดหน้า left
        prev = prev->next;
    }
    struct ListNode* cur = prev->next; //จิ้มตัวแรกที่จะกลับลำดับ
    for (int i = 0; i < right - left; i++) {
        struct ListNode* temp = cur->next; //ตัวถัดไป
        cur->next = temp->next; //ตัวปัจจุบันชี้ข้ามไป
        temp->next = prev->next; //ท้ายชี้ไปหัวเพื่อเป็นหัวตัวใหม่
        prev->next = temp; //ชี้ไปที่หัวใหม่
    } 

    return dummy.next;
}