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
    ListNode* Reverse(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = nullptr;

        while(temp != nullptr){
            ListNode* next = temp->next;
            temp->next = prev;

            prev = temp;
            temp = next;
        }
        return prev;
    }
    void reorderList(ListNode* head){

        if(head == nullptr || head->next == nullptr) return;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* second = slow->next;
        slow->next = nullptr;

        second = Reverse(second);
        ListNode* first = head;

        while(second != nullptr){
        ListNode* firstnext = first->next;
        ListNode* secondnext = second->next;

        first->next = second;
        second->next = firstnext;

        first = firstnext;
        second = secondnext;
        }
    }
};