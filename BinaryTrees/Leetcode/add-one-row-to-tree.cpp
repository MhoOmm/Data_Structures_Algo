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
    void dfs(TreeNode* root, int val, int depth,int d){
        if(!root)
        {
            return;
        }
        if(d+1==depth)
        {
            TreeNode* nodeL = new  TreeNode(val);
            nodeL->left = root->left;
            root->left = nodeL;
            TreeNode* nodeR = new TreeNode(val);
            nodeR->right = root->right;
            root->right = nodeR;
            return;
        }
        dfs(root->left,val,depth,d+1);
        dfs(root->right,val,depth,d+1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newR = new TreeNode(val);
            newR->left = root;
            return newR;
        }
        dfs(root,val,depth,1);
        return root;
    }
};