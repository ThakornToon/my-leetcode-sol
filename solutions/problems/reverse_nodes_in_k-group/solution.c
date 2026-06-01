/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// ฟังก์ชันช่วยในการกลับลำดับย่อย
struct ListNode* reverseLinkedList(struct ListNode* head, int k) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next = NULL;
    
    // กลับลำดับ k โหนด
    for (int i = 0; i < k && curr != NULL; i++) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    // head กลายเป็น tail ของส่วนที่กลับแล้ว
    head->next = curr;
    return prev; // คืน head ใหม่ของส่วนที่กลับแล้ว
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (head == NULL || k == 1) return head;
    
    // สร้าง dummy node
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    
    struct ListNode* prevGroupEnd = dummy;
    struct ListNode* curr = head;
    
    while (curr != NULL) {
        // ตรวจสอบว่ามีอย่างน้อย k โหนดไหม
        struct ListNode* checker = curr;
        int count = 0;
        while (count < k && checker != NULL) {
            checker = checker->next;
            count++;
        }
        
        if (count == k) {
            // มี k โหนด ให้กลับลำดับ
            struct ListNode* nextGroupStart = checker;
            struct ListNode* groupHead = curr;
            
            // กลับลำดับกลุ่มปัจจุบัน
            struct ListNode* newGroupHead = reverseLinkedList(groupHead, k);
            
            // เชื่อมต่อกับส่วนก่อนหน้า
            prevGroupEnd->next = newGroupHead;
            
            // อัปเดต pointer
            prevGroupEnd = groupHead; // groupHead กลายเป็น tail ของกลุ่มที่กลับแล้ว
            curr = nextGroupStart;
        } else {
            // เหลือน้อยกว่า k โหนด ไม่ต้องกลับ
            break;
        }
    }
    
    struct ListNode* newHead = dummy->next;
    free(dummy);
    return newHead;
}