/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int stack1[100], stack2[100];
    int top1 = -1, top2 = -1;
    
    // เติมค่าเข้า stack สำหรับ l1
    while (l1 != NULL) {
        stack1[++top1] = l1->val;
        l1 = l1->next;
    }
    
    // เติมค่าเข้า stack สำหรับ l2
    while (l2 != NULL) {
        stack2[++top2] = l2->val;
        l2 = l2->next;
    }
    
    int carry = 0;
    struct ListNode* result = NULL; // result = NULL แค่สร้าง pointer ที่ยังไม่ชี้ไปที่ memory ใดๆ เราจะ malloc เมื่อสร้างโหนดใหม่จริงๆ ในลูป (newNode = malloc(...))
    
    // ดึงค่าจาก stack มาบวกกัน
    while (top1 >= 0 || top2 >= 0 || carry != 0) {
        int sum = carry;
        
        if (top1 >= 0) {
            sum += stack1[top1--];
        }
        
        if (top2 >= 0) {
            sum += stack2[top2--];
        }
        
        carry = sum / 10;
        int digit = sum % 10;
        
        // สร้างโหนดใหม่และเชื่อมกับผลลัพธ์ที่สร้างไว้ก่อนหน้า
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = digit;
        newNode->next = result;
        result = newNode;
    }
    
    return result;
}