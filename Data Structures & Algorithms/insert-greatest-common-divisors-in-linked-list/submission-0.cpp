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
    int FindGCD(int a, int b){
        while(b != 0){
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {

        if(head == nullptr || head->next == nullptr) return head;

        ListNode* node1 = head;
        ListNode* node2 = head->next;

        while(node2 != nullptr){
            
        int GCD = FindGCD(node1->val, node2->val);
        ListNode* GCDNode = new ListNode(GCD);

        node1->next = GCDNode;
        GCDNode->next = node2;

        node1 = node2;
        node2 = node2->next;
  
        }
        return head;
    }
};