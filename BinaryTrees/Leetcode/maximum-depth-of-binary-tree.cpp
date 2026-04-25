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
    int maxCount;
    void traverse(TreeNode* root,int count)
    {
        if(root==NULL)
        {
            return;
        }

        if(root->left==NULL && root->right==NULL)
        {
            maxCount = max(maxCount,count+1);
            return;
        }

        traverse(root->left,count+1);
        traverse(root->right,count+1);
    }
    int maxDepth(TreeNode* root) {
        maxCount = 0;
        if(root==NULL)return 0;
        traverse(root,0);
        return maxCount;
    }
};