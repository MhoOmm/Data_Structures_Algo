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

        if (!head || !head->next || k == 0)
            return head;

        ListNode* temp  = head;
        int n =1;
        while(temp->next!=NULL)
        {
            temp =temp->next;
            n++;
        }

        temp->next = head; 
        k = k % n;
        int count  = n-k;
        ListNode* last = head;
        for (int i = 1; i < count; i++) {
            last = last->next;
        } 
        ListNode* result = last->next;
        last->next = NULL;

        return result;
    }
};