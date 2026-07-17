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
    bool dfs(TreeNode* p,TreeNode* q,TreeNode* root1,TreeNode* root2)
    {
        if (root1 == nullptr && root2 == nullptr){
            return true;
        }
        if (root1 == nullptr || root2 == nullptr){
            return false;
        }
        if(root1->val != root2->val)
        {
            return false;
        }

        return dfs(p,q,root1->left,root2->left) && dfs(p,q,root1->right,root2->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        TreeNode* root1 = p;
        TreeNode* root2 = q;
        return dfs(p,q,root1,root2);
    }
};