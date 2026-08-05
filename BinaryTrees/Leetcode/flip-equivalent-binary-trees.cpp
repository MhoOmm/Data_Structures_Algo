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
    bool solve(TreeNode* root1, TreeNode* root2)
    {
        // base case
        if(!root1 && !root2)
        {
            // we have reached the end
            return true;
        }
        if(!root1 || !root2)
        {
            return false;
        }
        if (root1->val != root2->val){
            return false;
        }
        // check if parent and both child are equal
        // No Flip
        bool leftAnsNf  = solve(root1->left,root2->left);
        bool rightAnsNf = solve(root1->right,root2->right);
        bool noflip = leftAnsNf && rightAnsNf;
        // Flip
        bool leftAnsF  = solve(root1->left,root2->right);
        bool rightAnsF = solve(root1->right,root2->left);
        bool flip = leftAnsF && rightAnsF;

        return noflip || flip;
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if((root1 && !root2) || (!root1 && root2) )
        {
            return false;
        }
        return solve(root1,root2);
    }
};