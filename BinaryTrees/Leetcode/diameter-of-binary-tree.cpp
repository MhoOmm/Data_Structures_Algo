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
    int diam;
    int maxDiam(TreeNode* node)
    {
        if(node== NULL)
        {
            return 0;//leaf node
        }

        int leftdiam = maxDiam(node->left);
        int rightdiam = maxDiam(node->right);

        diam = max(diam,leftdiam+rightdiam);

        // i will return to my parent 1+ max(left,right) i.e, best path
        return max(leftdiam,rightdiam)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        diam = 0;
        maxDiam(root);
        return diam;
    }
};