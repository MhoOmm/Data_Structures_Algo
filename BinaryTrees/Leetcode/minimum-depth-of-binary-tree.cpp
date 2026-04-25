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
    int minCount;
    void traverse(TreeNode* root,int count)
    {
        if(root==NULL)
        {
            return;
        }

        if(root->left==NULL && root->right==NULL)
        {
            minCount = min(minCount,count+1);
            return;
        }

        traverse(root->left,count+1);
        traverse(root->right,count+1);
    }
    int minDepth(TreeNode* root) {
        minCount= INT_MAX;
        if(root==NULL)return 0;
        traverse(root,0);
        return minCount;
    }
};