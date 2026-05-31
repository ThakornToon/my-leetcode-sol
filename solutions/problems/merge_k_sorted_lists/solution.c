/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// ฟังก์ชัน merge สองลิสต์ที่เรียงแล้ว
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;
    
    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

// ฟังก์ชัน recursive แบ่งครึ่งและ merge
struct ListNode* mergeKListsHelper(struct ListNode** lists, int left, int right) {
    if (left > right) return NULL;
    if (left == right) return lists[left];
    
    int mid = left + (right - left) / 2;
    struct ListNode* l1 = mergeKListsHelper(lists, left, mid);
    struct ListNode* l2 = mergeKListsHelper(lists, mid + 1, right);
    
    return mergeTwoLists(l1, l2);
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0) return NULL;
    return mergeKListsHelper(lists, 0, listsSize - 1);
}