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
    ListNode* Merge(ListNode* head1, ListNode* head2){
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while(head1 && head2){
            if(head1->val > head2->val){
                curr->next = head2;
                head2 = head2->next;
            } else {
                curr->next = head1;
                head1 = head1->next;
            }
            curr = curr->next;
        }
        if(head1 == nullptr) curr->next = head2;
        else curr->next = head1;
        return dummy->next;
    }
    void mergelist(vector<ListNode*>& lists, int left, int right){
        if(left >= right) return;
        int mid = left + (right - left) / 2;
        mergelist(lists, left, mid);
        mergelist(lists, mid+1, right);

        lists[left] = Merge(lists[left], lists[mid+1]);
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        mergelist(lists, 0, lists.size()-1);
        return lists[0];
    }
};
