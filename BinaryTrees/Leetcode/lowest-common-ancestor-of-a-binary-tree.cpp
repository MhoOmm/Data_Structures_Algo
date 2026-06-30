/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lca(TreeNode* node, TreeNode* p, TreeNode* q)
    {
        if(node==nullptr)
        {
            return NULL;
        }
        // if node==p or node == q return the value
        if(node==p || node==q)
        {
            return node;
        }

        //left subtree se value 
        TreeNode* left = lca(node->left,p,q);
        // right subtree se value
        TreeNode* right = lca(node->right,p,q);

        if(left!=NULL && right!=NULL){
            return node;
        }
        if(left!=NULL){
            return left;
        }
        return right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
        {
            return NULL;
        }
        return lca(root,p,q);
    }
};