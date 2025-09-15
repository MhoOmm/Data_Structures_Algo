class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int result = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            result = result * 2 + temp->val; 
            temp = temp->next;
        }
        return result;
    }
};
