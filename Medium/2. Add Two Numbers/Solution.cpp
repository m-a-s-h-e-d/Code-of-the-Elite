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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carryOver = 0;
        
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        ListNode* answerHead = new ListNode();
        ListNode* answerPtr = answerHead;
        
        while (ptr1 || ptr2 || carryOver > 0) {
            // Gather digits and add together with carry over
            int d1 = (ptr1) ? ptr1->val : 0;
            int d2 = (ptr2) ? ptr2->val : 0;
            int sum = d1 + d2 + carryOver;
            
            // Calculate carry over and set value after reducing to single digit
            carryOver = sum / 10;
            answerPtr->val = sum % 10;
            
            // Shift pointer for l1
            if (ptr1) {
                ptr1 = ptr1->next;
            }
            // Shift pointer for l2
            if (ptr2) {
                ptr2 = ptr2->next;
            }
            // Create and shift pointer for answer list if necessary
            if (ptr1 || ptr2 || carryOver > 0) {
                answerPtr->next = new ListNode();
                answerPtr = answerPtr->next;
            }
        }
        
        return answerHead;
    }
};