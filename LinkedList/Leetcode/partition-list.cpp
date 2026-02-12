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
    ListNode* partition(ListNode* head, int x) {

        ListNode* temp = head;
        ListNode* small = new ListNode(0);
        ListNode* big = new ListNode(0);

        ListNode* smp  = small;
        ListNode* bigp = big;

        while(temp!=nullptr)
        {
            if(temp->val<x)
            {
                smp->next = temp;
                smp= smp->next;
            }
            else{
                bigp->next = temp;
                bigp = bigp->next;
            }
            temp = temp->next;
        }
        bigp->next  = NULL;
        smp->next = big->next;
        return small->next;
    }
};