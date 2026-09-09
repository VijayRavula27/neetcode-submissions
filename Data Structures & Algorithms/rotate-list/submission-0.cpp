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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return head;

        ListNode* temp = head;
        int length = 1;

        while(temp->next != nullptr){
            temp = temp->next;
            length++;
        }
        int position = k % length;
        if(position == 0) return head;

        ListNode* curr = head;
        for(int i = 0; i < length - position - 1; i++){
            curr = curr->next;
        }
        ListNode* newhead = curr->next;
        curr->next = nullptr;

        temp->next = head;

        return newhead;
    }
};