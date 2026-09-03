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
    private:
    ListNode* Reverse(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        ListNode* temp = head;

        while(temp != nullptr){
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = Reverse(l1);
        l2 = Reverse(l2);

         ListNode* l3 = new ListNode(0);
         ListNode* head = l3;
         int carry = 0;

         while(l1 != nullptr && l2 != nullptr){
            int value = l1->val + l2->val + carry;
            carry = value / 10;
            l3->next = new ListNode(value % 10);
            l1 = l1->next;
            l2 = l2->next;
            l3 = l3->next;
         }
         while(l1 != nullptr){
            int value = l1->val + carry;
            carry = value / 10;
            l3->next = new ListNode(value % 10);
            l1 = l1->next;
            l3 = l3->next;
         }
         while(l2 != nullptr){
            int value = l2->val + carry;
            carry = value / 10;
            l3->next = new ListNode(value % 10);
            l2 = l2->next;
            l3 = l3->next;
         }
         if(carry){
            l3->next = new ListNode(carry);
         }
         return Reverse(head->next);
    }
};