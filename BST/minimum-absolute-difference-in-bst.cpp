// same question 
// 783. Minimum Distance Between BST Nodes


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
    TreeNode* prev;
    int minDiff;
    void inorder(TreeNode* root)
    {
        if(root==nullptr)
        {
            return;
        }
        // left
        inorder(root->left);
        if(prev!=nullptr)
        {
            int diff = abs(root->val - prev->val);
            minDiff = min(minDiff,diff);
        }
        prev = root;
        inorder(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        prev = nullptr;
        minDiff = INT_MAX;
        inorder(root);
        return minDiff;
    }

};