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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* previous = &dummy;
        ListNode* current = head;
        
        while(current) {
            ListNode* next_node = current->next;
            while(next_node && current->val == next_node->val) { //เลื่อน next_node จนไม่เจอโหนดซ้ำ
                ListNode *temp = next_node->next;
                delete next_node;
                next_node = temp;
            }
            
            if(current->next == next_node) { //เป็นการเปรียบเทียบตำแหน่งหน่วยความจำ กรณีมีโหนดซ้ำเมื่อถูกลบไป current->next ยังชี้ไปที่เดิมแต่เราไม่ได้มีการ deref เข้าถึง val จึงทำได้
                previous = current; //ถ้าไม่เจอโหนดซ้ำ
            } 
            else { //ถ้าเจอโหนดซ้ำ
                previous->next = next_node;
                delete current;
            }
            current =  next_node;
        }
        return dummy.next;
    }
};