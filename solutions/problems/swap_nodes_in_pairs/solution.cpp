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
    ListNode* swapPairs(ListNode* head) {
        // Base case: ถ้าไม่มีโหนดหรือมีแค่โหนดเดียว ไม่ต้องสลับ
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        // กำหนด pointer สำหรับคู่แรก
        ListNode* first = head;
        ListNode* second = head->next;
        
        // สลับคู่แรก
        first->next = swapPairs(second->next); // สลับส่วนที่เหลือแบบ recursive
        second->next = first;
        
        // คืน head ใหม่ (second กลายเป็นหัวของลิสต์ที่สลับแล้ว)
        return second;
    }
};