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
    int sum ;
    void inorder(TreeNode* root)
    {
        if(root==NULL)
        {
            return ;
        }
        if(root->left && (root->left->left==NULL && root->left->right== NULL))
        {
            sum+=(root->left->val);
        }

        inorder(root->left);
        inorder(root->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        sum = 0;
        inorder(root);
        return sum;
    }
};