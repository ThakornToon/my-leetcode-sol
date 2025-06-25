/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    int getLength(ListNode *head) {
        int length = 0;
        while (head) {
            length++;
            head = head->next;
        }
        return length;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // ขั้นตอนที่ 1: หาความยาวของทั้งสอง List
        int lenA = getLength(headA);
        int lenB = getLength(headB);
        
        // ขั้นตอนที่ 2: ย้าย pointer ของ List ที่ยาวกว่า
        ListNode *currA = headA;
        ListNode *currB = headB;
        
        if (lenA > lenB) {
            for (int i = 0; i < lenA - lenB; ++i) {
                currA = currA->next;
            }
        } else {
            for (int i = 0; i < lenB - lenA; ++i) {
                currB = currB->next;
            }
        }
        
        // ขั้นตอนที่ 3: หาจุดตัดกัน
        while (currA && currB) {
            if (currA == currB) {
                return currA;
            }
            currA = currA->next;
            currB = currB->next;
        }
        
        return nullptr;
    }
};