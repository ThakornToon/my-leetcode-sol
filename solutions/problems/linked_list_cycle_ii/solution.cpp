/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return nullptr;
        
        ListNode *slow = head, *fast = head;
        
        // Detection phase
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        
        if (slow != fast) return nullptr; // No cycle
        
        // Finding phase
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
/*
เมื่อ slow และ fast พบกันครั้งแรก เรารู้ว่า linked list มี cycle
จุดนี้ที่พบกัน slow เคลื่อนที่ไปแล้ว x + y ระยะ
fast เคลื่อนที่ไปแล้ว x + 2y + z = 2(x + y) ระยะ (โดย x คือระยะจาก head ถึงจุดเริ่ม cycle, y คือระยะใน cycle ก่อนพบกัน, z คือระยะที่เหลือใน cycle)
*/        
        return slow;
    }
};