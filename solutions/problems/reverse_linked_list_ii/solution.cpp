/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) {
            return head;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        for (int i = 0; i < left - 1; i++) { //หาโหนดหน้า left
            prev = prev->next;
        }
        ListNode* cur = prev->next; //จิ้มตัวแรกที่จะกลับลำดับ
        for (int i = 0; i < right - left; i++) {
            ListNode* temp = cur->next; //ตัวถัดไป
            cur->next = temp->next; //ตัวปัจจุบันชี้ข้ามไป
            temp->next = prev->next; //ท้ายชี้ไปหัวเพื่อเป็นหัวตัวใหม่
            prev->next = temp; //ชี้ไปที่หัวใหม่
        } 
        head = dummy->next;
        delete dummy;
        return head;
    }
};