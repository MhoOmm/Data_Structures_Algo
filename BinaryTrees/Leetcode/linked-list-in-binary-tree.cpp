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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool match(TreeNode* root,ListNode* temp)
    {
        if(temp==nullptr)
        {
            // we have processed correctly till now
            return true;
        }
        if(root == nullptr)
        {
            return false;
        }
        if (root->val != temp->val) {
            return false;
        }
        return match(root->left,temp->next) || match(root->right,temp->next);
    }
    bool solve(TreeNode* root,ListNode* temp)
    {
        if(root==nullptr)
        {
            return false;
        }
        if(match(root,temp)){
            return true;
        }
        return solve(root->left, temp) || solve(root->right, temp);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        return solve(root,head);
    }
};