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
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newhead = Reverse(slow);
        ListNode* first = head;
        ListNode* second = newhead;

        while(second != nullptr){

            if(first->val != second->val) return false;

            first = first->next;
            second = second->next;
        }
        return true;
    }
};