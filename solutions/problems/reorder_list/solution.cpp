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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        
        // Step 1: หา middle node ด้วย two pointers
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Step 2: Reverse ครึ่งหลัง
        ListNode* prev = nullptr;
        ListNode* curr = slow->next;  // curr คือ ตัวแรกของครึ่งหลัง
        slow->next = nullptr; // ตัด connection ที่เชื่อมกับครึ่งแรก
        
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        ListNode* secondHalf = prev;  // ตัวที่ 1 ของครึ่งหลังอันใหม่
        
        // Step 3: Merge สลับกัน
        ListNode* first = head;  // ครึ่งแรก
        ListNode* second = secondHalf;  // ครึ่งหลัง
        
        while (second) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;
            
            first->next = second;
            second->next = temp1;
            
            first = temp1;
            second = temp2;
        }
    }
};