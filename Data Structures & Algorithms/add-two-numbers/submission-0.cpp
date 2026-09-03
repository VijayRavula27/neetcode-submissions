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
        ListNode* dummy = new ListNode(0);
        ListNode* l3 = dummy;
        int value = 0;
        int carry = 0;

        while(l1 && l2){
            value = l1->val + l2->val + carry;
            carry = value / 10;
            l3->next = new ListNode(value % 10);
            l3 = l3->next;
            l2 = l2->next;
            l1 = l1->next;
        }
         while(l1){
            value = l1->val + carry;
            carry = value / 10;
            l3->next = new ListNode(value % 10);
            l3 = l3->next;
            l1 = l1->next;
        }
         while(l2){
            value = l2->val + carry;
            carry = value / 10;
            l3->next = new ListNode(value % 10);
            l3 = l3->next;
            l2 = l2->next;
        }
        if(carry != 0){
            l3->next = new ListNode(carry);
        }
        return dummy->next;
    }
};
